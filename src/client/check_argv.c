/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:30:06 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/13 19:42:20 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

int check_argv(int argc)
{
	if(argc == 2)
		return(TRUE);
	ft_putstr_fd("Invalid arguments\n",2);
	ft_putstr_fd("Correct: ./server PID MESSEGE",2);
	exit(EXIT_FAILURE);
}