/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:19:30 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/19 20:41:24 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	bool	is_negative;
	int		result;

	while (*str == '\t' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == '\n' || *str == ' ')
		str ++;
	is_negative = false;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = true;
		str ++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		if (is_negative)
			result -= *str - '0';
		else
			result += *str - '0';
		str ++;
	}
	return (result);
}
