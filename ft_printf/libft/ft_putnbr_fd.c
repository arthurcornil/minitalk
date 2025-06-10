/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:55:18 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/10 15:56:42 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_floored(int nb)
{
	int	digit_counter;

	digit_counter = 1;
	while (nb / 10 != 0)
	{
		nb /= 10;
		digit_counter *= 10;
	}
	return (digit_counter);
}

void	ft_putdigit(int d, int fd)
{
	char	c;

	c = d + '0';
	write (fd, &c, 1);
}

void	ft_putnbr_fd(long int nb, int fd)
{
	long int	number;
	int			floored_nb;
	int			curr_digit;

	number = nb;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	floored_nb = ft_get_floored(number);
	while (floored_nb > 0)
	{
		curr_digit = number / floored_nb;
		ft_putdigit(curr_digit, fd);
		number %= floored_nb;
		floored_nb /= 10;
	}
}
