/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:03:31 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/24 13:21:41 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../Libft/include/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "server.h"


# define CHAR_0 SIGUSR1
# define CHAR_1 SIGUSR2

# define TRUE 1
# define FALSE 0

typedef enum e_server_state
{
	IDLE = 0,
	RCV_SIZE = 1,
	RCV_MSG = 2
}	t_server_state;

typedef struct s_data
{
	pid_t 	client_pid;
	pid_t 	server_pid;
	char 	*msg;
} t_info;

typedef struct s_client_global
{
	t_server_state			state;
	pid_t					server_pid;
	pid_t					client_pid;
	size_t					msg_size;
	char					*msg;
	volatile sig_atomic_t	is_ready;
}	t_client_global;

extern t_client_global g_c;

int check_argv(int argc);


#endif