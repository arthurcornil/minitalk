/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:14:55 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/20 12:34:48 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdbool.h>
# include <signal.h>
# include <limits.h>
# include "ft_printf/includes/ft_printf.h"

typedef struct s_byte
{
	unsigned char	byte;
	size_t			curr_bit;
}	t_byte;

int		ft_atoi(const char *str);

#endif
