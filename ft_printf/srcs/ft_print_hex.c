/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:38:45 by arcornil          #+#    #+#             */
/*   Updated: 2025/03/17 13:23:25 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_num(unsigned int num, char *base)
{
	int	lengthbase;

	lengthbase = 16;
	if (num >= (unsigned int)lengthbase)
	{
		ft_print_num(num / lengthbase, base);
		num %= lengthbase;
	}
	ft_putchar_fd(*(base + num), 1);
}

static int	ft_get_ndigits_hex(unsigned int num)
{
	int	ndigits;

	ndigits = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		ndigits ++;
	}
	return (ndigits);
}

void	ft_print_hex(t_print *tab, bool uppercase)
{
	unsigned int	num;
	char			*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	num = va_arg(tab->args, unsigned int);
	tab->length += ft_get_ndigits_hex(num);
	ft_print_num(num, base);
}
