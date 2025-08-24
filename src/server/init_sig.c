/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:02:18 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/24 12:47:34 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void init_sig(void)
{
	struct sigaction sa;
	sigset_t	set;
	
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = client_signal_handler;// entender esta parte del codigo niceeee!!!!!!!!!
	sa.sa_mask	= set;
	sigaction(SIGUSR1,&sa,NULL);
	sigaction(SIGUSR2,&sa,NULL);
}
