/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:50:34 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/11 13:03:41 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_get_format(t_print *tab, const char *str, int pos)
{
	if (str[pos] == 'c')
		ft_print_char(tab);
	else if (str[pos] == 'd' || str[pos] == 'i')
		ft_print_int(tab);
	else if (str[pos] == 's')
		ft_print_str(tab);
	else if (str[pos] == 'u')
		ft_print_uint(tab);
	else if (str[pos] == '%')
		tab->length += write(1, "%", 1);
	else if (str[pos] == 'x')
		ft_print_hex(tab, false);
	else if (str[pos] == 'X')
		ft_print_hex(tab, true);
	else if (str[pos] == 'p')
		ft_print_ptr(tab);
	return (pos);
}
