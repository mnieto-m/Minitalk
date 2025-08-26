/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:27:14 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/26 20:45:33 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

unsigned char	bin_to_char(int *bin)
{
	int	bit_index;
	int	c;

	c = 0;
	bit_index = 0;
	while (bit_index < 8)
	{
		if (bin[bit_index] == 1)
			c = (c << 1) | 1;
		else
			c = (c << 1);
		bit_index++;
	}
	return ((unsigned char) c);
}

int	ft_pow(const int base, const int power)
{
	if (power == 1)
		return (base);
	else if (power == 0)
		return (1);
	else if (power < 0 || base == 0)
		return (0);
	return (base * ft_pow(base, power - 1));
}
