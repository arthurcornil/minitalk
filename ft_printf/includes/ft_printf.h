/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:24:08 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/08 10:24:55 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_print
{
	va_list		args;
	int			length;
}	t_print;

int				ft_printf(const char *format, ...);
int				ft_get_format(t_print *tab, const char *str, int pos);
void			ft_format_precision(t_print *tab, int len_elem);
void			ft_right_indent(t_print *tab, int len);
void			ft_left_indent(t_print *tab, int len_elem);
void			ft_print_char(t_print *tab);
void			ft_print_int(t_print *tab);
void			ft_print_uint(t_print *tab);
void			ft_print_str(t_print *tab);
void			ft_print_ptr(t_print *tab);
void			ft_print_hex(t_print *tab, bool uppercase);
void			ft_print_percent(t_print *tab);
int				ft_get_ndigits(int num);
unsigned int	ft_get_factor(unsigned int num);
void			ft_reset_tab(t_print *tab);
t_print			*ft_init_tab(t_print *tab);

#endif
