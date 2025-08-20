/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:25:59 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/20 16:25:18 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

t_global	glob_client;

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
	sigset_t	set;
	
	memset(&glob_client,0,sizeof(t_global));
	server_argc(argc);
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sigaction_handler();// entender esta parte del codigo niceeee!!!!!!!!!
	sa.sa_mask	= set;
	sig_action(SIGUSR1,&sa,NULL);
	sig_action(SIGUSR2,&sa,NULL);
	server_going();
}
