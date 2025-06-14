/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:25:59 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/06/14 16:32:48 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

t_global	g_server;

static int parse_server(int argc, char *argv) 
{
	if (argc < 1)
		return(TRUE);		
	t_putstr_fd("To many arguments", 2);
	exit(EXIT_FAILURE);
}


int main(int argc, char *argv)
{
	t_global	t_global;
	struct sigaction sa;
	parse_server(argc, argv);
	init_server(t_global);
}