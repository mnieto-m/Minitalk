/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:30:36 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/26 20:52:09 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

t_server_global g_server;

void	idle_signal_handler(int signum, int pid)
{
	(void) signum;
	if (signum != SIGUSR1)
		ft_printf("[ERROR] Incompatible signal with server state");
	g_server.state = RCV_SIZE;
	g_server.client_pid = pid;
	kill(pid, SIGUSR1);
}

void	rcv_size_signal_handler(int signum, int pid)
{
	static size_t	bit = 0;

	if (signum == SIGUSR1)
		g_server.mesg.size_message += ft_pow(2, 8 * sizeof(size_t) - bit - 1);
	bit++;
	if (bit >= 8 * sizeof(size_t))
	{
		if (g_server.mesg.size_message == 0)
		{
			free(g_server.mesg.str);
			g_server.mesg.str = NULL;
			g_server.state = IDLE;
		}
		else
		{
			g_server.state = RCV_MSG;
			g_server.mesg.str = malloc(g_server.mesg.size_message + 1);
			if (g_server.mesg.str == NULL)
				error_exit("[ERROR] Fail message memory allocation");
			ft_bzero(g_server.mesg.str, g_server.mesg.size_message + 1);
		}
		bit = 0;
	}
	kill(pid, SIGUSR1);
}

void	rcv_char(int signum)
{
	static int	bit = 0;
	static int	*binary_char;
	char		c;

	if (bit == 0)
	{
		binary_char = (int *) ft_calloc(8, sizeof(int));
		if (!binary_char)
			error_exit("[ERROR] Memory allocation");
	}
	if (signum == SIGUSR1)
		binary_char[bit] = 1;
	else if (signum == SIGUSR2)
		binary_char[bit] = 0;
	bit++;
	if (bit == 8)
	{
		c = (char) bin_to_char(binary_char);
		ft_strlcat(g_server.mesg.str, &c, 1);
		bit = 0;
		if (binary_char)
			free(binary_char);
	}
}

void	rcv_msg_signal_handler(int signum, int pid)
{
	rcv_char(signum);
	if (ft_strlen(g_server.mesg.str) >= (size_t)g_server.mesg.size_message)
	{
		ft_printf("%s\n", g_server.mesg.str);
		free(g_server.mesg.str);
		g_server.mesg.str = NULL;
		g_server.state = IDLE;
		kill(pid, SIGUSR1);
		return ;
	}
	kill(pid, SIGUSR1);
}

void	client_signal_handler(int signum, siginfo_t *info, void *context)
{
	int	pid;

	(void) context;
	memset(&g_server,0,sizeof(t_server_global));
	if (g_server.pid_server == 0)
		g_server.pid_server = getpid();
	pid = info->si_pid;
	if (g_server.state == IDLE)
		idle_signal_handler(signum, pid);
	else if (pid != g_server.client_pid || pid == 0)
		return ;
	else if (g_server.state == RCV_SIZE)
		rcv_size_signal_handler(signum, pid);
	else if (g_server.state == RCV_MSG)
		rcv_msg_signal_handler(signum, pid);
}
