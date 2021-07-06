/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:06:20 by vcavalca          #+#    #+#             */
/*   Updated: 2021/07/06 14:10:21 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(va_list args, t_printf *flag, int ret)
{
	char	type;

	type = flag->type;
	if (type == 'c')
		ret = ft_print_char(va_arg(args, int), flag, ret);
	else if (type == 's')
		ret = ft_print_str(va_arg(args, char *), flag, ret);
	else if (type == 'p')
		ret = ft_print_p(flag, va_arg(args, unsigned long long), ret);
	else if (type == 'd' || type == 'i')
		ret = ft_print_nbr(va_arg(args, int), flag, ret);
	else if (type == 'u')
		ret = ft_print_nbr(va_arg(args, unsigned int), flag, ret);
	else if (type == 'x' || type == 'X')
		ret = ft_print_x(flag, va_arg(args, unsigned int), ret);
	else if (type == '%')
		ret = ft_print_char('%', flag, ret);
	else
		ret = ft_print_n(flag, ret);
	return (ret);
}

int	ft_check_flag(char *fmt, t_printf *flag, va_list args, int i)
{
	if (fmt[i] == '-')
		flag->min = 1;
	else if (fmt[i] == '0')
		flag->zero = 1;
	else if (fmt[i] == '*' || ft_isdigit(fmt[i]))
		i = ft_set_width(fmt, flag, args, i);
	else
	{
		if (fmt[i] == '.')
			i = ft_set_precision(fmt, flag, args, i);
	}
	return (i);
}

int	ft_check_loop(char fmt)
{
	if (ft_strchr("0-.*", fmt) != 0 || ft_isdigit(fmt))
		return (1);
	else
		return (0);
}

int	ft_check_fmt(va_list args, char *fmt, int ret, t_printf *flag)
{
	int	i;

	i = 0;
	while (fmt[i])
	{
		while (fmt[i] != '%' && fmt[i] != '\0')
		{
			write(1, &fmt[i++], 1);
			ret++;
		}
		if (fmt[i] == '%')
		{
			ft_flag_init(flag);
			i++;
			while (fmt[i] != '\0' && ft_check_loop(fmt[i]))
				i = ft_check_flag(fmt, flag, args, i) + 1;
			if (fmt[i] == '\0')
				continue ;
			else
				i = ft_set_type(fmt, flag, i);
			ret = ft_check_type(args, flag, ret);
		}
	}
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	int			ret;
	t_printf	*flag;
	va_list		args;

	ret = 0;
	va_start(args, fmt);
	flag = malloc(sizeof(t_printf));
	if (!flag)
		return (-1);
	ret = ft_check_fmt(args, (char *)fmt, ret, flag);
	va_end(args);
	free(flag);
	return (ret);
}
