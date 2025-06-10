/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:46:39 by arcornil          #+#    #+#             */
/*   Updated: 2025/03/17 12:48:47 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_get_ndigits(int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	if (num < 0)
		i ++;
	while (num != 0)
	{
		num /= 10;
		i ++;
	}
	return (i);
}

unsigned int	ft_get_factor(unsigned int num)
{
	unsigned int	factor;

	factor = 1;
	while (num >= 10)
	{
		num /= 10;
		factor *= 10;
	}
	return (factor);
}
