/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:54:56 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/06/14 16:38:53 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../Libft/include/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

typedef struct s_msg
{
	int		size_message;
	char	*message;
}	t_msg;

typedef struct s_global
{
	volatile sig_atomic_t	client_pid;
	volatile sig_atomic_t	actual_pid;
	volatile sig_atomic_t	getting_header;
	volatile sig_atomic_t	getting_msg;
	volatile sig_atomic_t	client_activity;
	volatile sig_atomic_t	sig_count;
	char					char_value;
	volatile sig_atomic_t	msg_pos;
}	t_global;

extern t_global g_server;

#endif