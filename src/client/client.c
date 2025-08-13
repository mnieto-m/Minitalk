/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:25:59 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/13 17:58:36 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

/* static int parse_client(int argc, char *argv) 
{
	if (argc == 2)
	{
		
	}

	

} */


int main(int argc, char **argv)
{
	check_argv(argc);
	if(argv[1] != NULL)
		printf("holaaa");
	//parse_client(argc, argv);

}