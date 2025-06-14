/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:25:59 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/06/14 17:36:37 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

t_global	g_server;

static int server_argc(int argc) 
{
	if (argc < 2)
		return(TRUE);	
	ft_putstr_fd("To many arguments", 2);
	exit(EXIT_FAILURE);
}


int main(int argc, char **argv)
{
	//t_global	t_global;
	//struct sigaction sa;
	server_argc(argc);
	if(argv[1] != NULL)
		printf("holaaa");
	//init_server(t_global);
}