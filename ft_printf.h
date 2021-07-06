/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:06:16 by vcavalca          #+#    #+#             */
/*   Updated: 2021/07/06 14:05:44 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_printf
{
	int		min;
	int		zero;
	int		star;
	int		width;
	int		dot;
	int		prec;
	int		nbr_m;
	char	type;
}				t_printf;

int		ft_printf(const char *fmt, ...);
int		ft_check_fmt(va_list args, char *fmt, int ret, t_printf *flag);
int		ft_check_loop(char fmt);
int		ft_check_flag(char *fmt, t_printf *flag, va_list args, int i);
int		ft_check_type(va_list args, t_printf *flag, int ret);
int		ft_print_n(t_printf *flag, int ret);
int		ft_print_p(t_printf *flag, unsigned long long num, int ret);
int		ft_p_right(t_printf *flag, unsigned long long num, int ret);
int		ft_p_left(t_printf *flag, unsigned long long num, int ret);
int		ft_p_star(t_printf *flag, unsigned long long num, int ret);
int		ft_print_char(int i, t_printf *flag, int ret);
int		ft_char_star(t_printf *flag, int ret);
int		ft_print_x(t_printf *flag, unsigned int num, int ret);
int		ft_not_dot(unsigned int num, t_printf *flag, int ret);
int		ft_is_dot(unsigned int num, t_printf *flag, int ret);
int		ft_print_right(unsigned int num, t_printf *flag, int ret);
int		ft_print_left(unsigned int num, t_printf *flag, int ret);
int		ft_print_star(unsigned int num, t_printf *flag, int ret);
int		ft_print_zero(unsigned int num, t_printf *flag, int ret);
int		ft_print_str(char *s, t_printf *flag, int ret);
int		ft_str_null(t_printf *flag, int ret);
int		ft_is_str(char *s, t_printf *flag, int ret);
int		ft_str_zero(char *s, t_printf *flag, int ret);
int		ft_str_star(char *s, t_printf *flag, int ret);
int		ft_check_minus(t_printf *flag, int ret);
int		ft_min_integer(t_printf *flag, int ret);
int		ft_print_nbr(int n, t_printf *flag, int ret);
int		ft_set_precision(char *format, t_printf *flag, va_list args, int i);
int		ft_set_width(char *format, t_printf *flag, va_list args, int i);
int		ft_set_type(char *format, t_printf *flag, int i);
int		ft_nbr_len(unsigned long long n, char x);

void	ft_nbr(unsigned int num, char x);
void	ft_flag_init(t_printf *flag);
void	ft_write_nbr(unsigned long long n, char x, unsigned int base);

#endif
