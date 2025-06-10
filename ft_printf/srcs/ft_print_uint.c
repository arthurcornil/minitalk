/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:41:10 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/21 18:00:43 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putuint(unsigned int num, t_print *tab)
{
	unsigned int		factor;
	char				digit;

	factor = ft_get_factor(num);
	while (factor != 0)
	{
		digit = (num / factor) + '0';
		tab->length += write(1, &digit, 1);
		num %= factor;
		factor /= 10;
	}
}

void	ft_print_uint(t_print *tab)
{
	unsigned int	num;

	num = va_arg(tab->args, unsigned int);
	ft_putuint(num, tab);
}
