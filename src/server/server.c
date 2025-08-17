/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:25:59 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/17 13:07:10 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

t_global	s_server;

static int server_argc(int argc) 
{
	if (argc < 2)
		return(TRUE);	
	ft_putstr_fd("To many arguments", 2);
	exit(EXIT_FAILURE);
}


int main(int argc, char **argv)
{
	struct sigaction sa;
	
	server_argc(argc);
	sigemptyset(s_server.sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	//init_server();
	//register_sig_handler();
}
