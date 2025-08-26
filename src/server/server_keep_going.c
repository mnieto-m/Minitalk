/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_keep_going.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:44:35 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/26 20:56:38 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

void	clean_global(void)
{
	g_server.client_activity = 0;
	if (g_server.mesg.str != NULL)
	{
		write(2, "There was a problem with the last client\n", 42);
		free(g_server.mesg.str);
	}
	ft_bzero(&g_server, sizeof(g_server));
}

int	check_clean_status(void)
{
	int	i;

	if(g_server.actual_pid == 0)
		return (sleep (1), 1);
	i = 0;
	while (i < TIMEOUT)
	{
		usleep(SLEEP_TIME);
		if (g_server.client_activity)
		{
			g_server.client_activity = 0;
			i = 0;
		}
		i++;
	}
	if (i == TIMEOUT)
		clean_global();
	return (0);
}

void	keep_server_up(void)
{
	while (1)
		check_clean_status();
}