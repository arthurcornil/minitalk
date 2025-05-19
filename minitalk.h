/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:14:55 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/19 17:55:02 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <signal.h>
# include <limits.h>

void	ft_putstr_fd(int fd, char *str);
int		ft_atoi(const char *str);

#endif
