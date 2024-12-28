/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:03:31 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/12/28 18:35:38 by mnieto-m         ###   ########.fr       */
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


# define KO_MESSAGE "Bad argv: \n ./client [PID_SERVER] [MESSAGE]"
# define BAD_SIGNAL "Signal sending failed: Operation not permitted."

# define CHAR_0 SIGUSR1
# define CHAR_1 SIGUSR2

# define TRUE 0
# define FALSE 1

typedef struct s_data
{
	pid_t 	client_pid;
	pid_t 	server_pid;
	char 	*msg;
} t_info;

typedef struct s_global
{
	int						pid;
	volatile sig_atomic_t	is_ready;
}	t_global;

extern t_global g_client;


#endif