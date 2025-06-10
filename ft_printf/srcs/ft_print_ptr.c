/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:59:48 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/03 12:44:10 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_ptr_to_hex(unsigned long num, char *base)
{
	unsigned long	lengthbase;

	lengthbase = 16;
	if (num >= lengthbase)
	{
		ft_ptr_to_hex(num / lengthbase, base);
		num %= lengthbase;
	}
	ft_putchar_fd(*(base + num), 1);
}

static unsigned int	ft_get_ndigits_ptr_to_hex(unsigned long ptr)
{
	int	ndigits;

	ndigits = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0)
	{
		ptr /= 16;
		ndigits ++;
	}
	return (ndigits);
}

void	ft_print_ptr(t_print *tab)
{
	unsigned long	ptr;

	ptr = va_arg(tab->args, unsigned long);
	if (!ptr)
	{
		tab->length += 5;
		ft_putstr_fd("(nil)", 1);
		return ;
	}
	tab->length += ft_get_ndigits_ptr_to_hex(ptr) + 2;
	write(1, "0x", 2);
	ft_ptr_to_hex(ptr, "0123456789abcdef");
}
