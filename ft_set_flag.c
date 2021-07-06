/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:06:10 by vcavalca          #+#    #+#             */
/*   Updated: 2021/07/06 14:10:58 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_init(t_printf *flag)
{
	flag->min = 0;
	flag->zero = 0;
	flag->star = 0;
	flag->width = 0;
	flag->dot = 0;
	flag->prec = 0;
	flag->nbr_m = 0;
	flag->type = 0;
}

int	ft_set_type(char *format, t_printf *flag, int i)
{
	if (ft_strchr("cspdiuxX%%", format[i]))
		flag->type = format[i++];
	else
		flag->type = 'n';
	return (i);
}

int	ft_set_width(char *format, t_printf *flag, va_list args, int i)
{
	int	width;

	width = 0;
	flag->star = 1;
	if (format[i] == '*')
	{
		flag->width = va_arg(args, int);
		if (flag->width < 0)
		{
			flag->min = 1;
			flag->width = -flag->width;
		}
	}
	else
	{
		while (ft_isdigit(format[i]))
			width = width * 10 + (format[i++] - '0');
		i--;
		flag->width = width;
	}
	return (i);
}

int	ft_set_precision(char *format, t_printf *flag, va_list args, int i)
{
	int	prec;

	prec = 0;
	flag->dot = 1;
	i++;
	if (ft_isdigit(format[i]))
	{
		while (ft_isdigit(format[i]))
			prec = prec * 10 + (format[i++] - '0');
		i--;
		flag->prec = prec;
	}
	else if (format[i] == '*')
		flag->prec = va_arg(args, int);
	else
	{
		flag->prec = 0;
		i--;
	}
	return (i);
}
