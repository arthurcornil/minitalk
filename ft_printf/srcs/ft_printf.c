/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:19:10 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/08 10:27:27 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_print	tab;
	int		i;

	tab.length = 0;
	va_start(tab.args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_get_format(&tab, format, i + 1);
		else
			tab.length += write(1, (format + i), 1);
		i ++;
	}
	va_end(tab.args);
	return (tab.length);
}
