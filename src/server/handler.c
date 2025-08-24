/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:19:42 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/24 13:23:02 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	idle_signal_handler(int signum, int pid, t_client_global *g)
{
	(void) signum;
	if (signum != SIGUSR1)
		ft_printf("[ERROR] Incompatible signal with server state");
	g->state = RCV_SIZE;
	g->client_pid = pid;
	kill(pid, SIGUSR1);
}

void	rcv_size_signal_handler(int signum, int pid, t_client_global *g)
{
	static size_t	bit = 0;

	if (signum == SIGUSR1)
		g->msg_size += ft_pow(2, 8 * sizeof(size_t) - bit - 1);
	bit++;
	if (bit >= 8 * sizeof(size_t))
	{
		if (g->msg_size == 0)
		{
			free(g->msg);
			g->msg = NULL;
			g->state = IDLE;
		}
		else
		{
			g->state = RCV_MSG;
			g->msg = malloc(g->msg_size + 1);
			if (g->msg == NULL)
				error_exit("[ERROR] Fail message memory allocation");
			ft_bzero(g->msg, g->msg_size + 1);
		}
		bit = 0;
	}
	kill(pid, SIGUSR1);
}

void	rcv_char(int signum, t_client_global *g)
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
		ft_strlcat(g->msg, &c, 1);
		bit = 0;
		if (binary_char)
			free(binary_char);
	}
}

void	rcv_msg_signal_handler(int signum, int pid, t_client_global *g)
{
	rcv_char(signum, g);
	if (ft_strlen(g->msg) >= g->msg_size)
	{
		ft_printf("%s\n", g->msg);
		free(g->msg);
		g->msg = NULL;
		g->state = IDLE;
		kill(pid, SIGUSR1);
		return ;
	}
	kill(pid, SIGUSR1);
}

void	client_signal_handler(int signum, siginfo_t *info, void *context)
{
	int				pid;

	(void) context;
	if (g_c.server_pid == 0)
		g_c.server_pid = getpid();
	pid = info->si_pid;
	if (g_c.state == IDLE)
		idle_signal_handler(signum, pid, &g_c);
	else if (pid != g_c.client_pid || pid == 0)
		return ;
	else if (g_c.state == RCV_SIZE)
		rcv_size_signal_handler(signum, pid, &g_c);
	else if (g_c.state == RCV_MSG)
		rcv_msg_signal_handler(signum, pid, &g_c);
}
