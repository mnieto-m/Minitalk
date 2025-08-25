/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:03:31 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/25 17:26:43 by mnieto-m         ###   ########.fr       */
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


# define CHAR_0 SIGUSR1
# define CHAR_1 SIGUSR2

# define TRUE 1
# define FALSE 0


typedef struct s_data
{
	pid_t 	client_pid;
	pid_t 	server_pid;
	char 	*msg;
} t_info;

typedef struct s_client_global
{
	pid_t					server_pid;
	pid_t					client_pid;
	size_t					msg_size;
	char					*msg;
	volatile sig_atomic_t	is_ready;
}	t_client_global;

extern t_client_global g_c;

int check_argv(int argc);


#endif