/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:25:59 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/15 16:17:04 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

/* static int parse_client(int argc, char *argv) 
{
	if (argc == 2)
	{
		
	}

	

} */

void check_pid(int atgc , char **argv)
{
	int flag;
	int pid; 

	flag = 0;
	pid = ft_atoi_signal(*argv[1], flag) ;
	if(flag == -1)
		ft_putstr_fd("Correct: ./server PID MESSEGE",2);
	
	
}


int main(int argc, char **argv)
{
	check_argv(argc);
	if(argv[1] != NULL)
		printf("holaaa");
	check_pid(argc, argv);

}