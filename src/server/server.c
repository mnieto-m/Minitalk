/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:25:59 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/25 17:30:15 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_server_global	g_s;

static int server_argc(int argc, char **argv) 
{
	if (argc < 2 || argv[0] != NULL)
		return(TRUE);	
	ft_putstr_fd("To many arguments", 2);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	ft_printf("Process PID: %d await for SIGUSR.\n", getpid());
	server_argc(argc, argv);
	init_sig();
	while (1)
		pause();
	exit(0);
}
