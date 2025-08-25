/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:54:56 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/25 17:26:50 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define _XOPEN_SOURCE 700

# include "../Libft/include/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>


# define TRUE 1
# define FALSE 0

typedef enum e_server_state
{
	IDLE = 0,
	RCV_SIZE = 1,
	RCV_MSG = 2
}	t_server_state;


typedef struct s_mesg
{
	int		size_message;
	char	*str;
}	t_mesg;

typedef struct s_server_global
{
	t_server_state			state;
	volatile sig_atomic_t	client_pid;
	volatile sig_atomic_t	actual_pid;
	volatile sig_atomic_t	client_activity;
	volatile sig_atomic_t	sig_count;
	char					char_value;
	volatile sig_atomic_t	mesg_pos;
	pid_t					pid_server;
	t_mesg					mesg;
}	t_server_global;

extern t_server_global g_server;

void init_sig(void);
void	client_signal_handler(int signum, siginfo_t *info, void *context);
void	error_exit(char *error_msg);
unsigned char	bin_to_char(int *bin);
int	ft_pow(const int base, const int power);


#endif