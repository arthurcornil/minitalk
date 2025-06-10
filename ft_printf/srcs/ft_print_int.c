/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:39:48 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/22 10:06:09 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_int(t_print *tab)
{
	int	num;

	num = va_arg(tab->args, int);
	tab->length += ft_get_ndigits(num);
	ft_putnbr_fd(num, 1);
}
