/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:06:26 by vcavalca          #+#    #+#             */
/*   Updated: 2021/07/06 13:50:13 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_star(char *s, t_printf *flag, int ret)
{
	if (flag->dot == 1)
	{
		while ((flag->width)-- > flag->prec)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	else if (flag->dot == 0)
	{
		while ((flag->width)-- > ft_strlen(s))
		{
			write(1, " ", 1);
			ret++;
		}
	}
	return (ret);
}

int	ft_str_zero(char *s, t_printf *flag, int ret)
{
	while ((flag->width)-- > ft_strlen(s))
	{
		write(1, "0", 1);
		ret++;
	}
	return (ret);
}

int	ft_is_str(char *s, t_printf *flag, int ret)
{
	int	len;

	if (flag->dot == 1)
		len = flag->prec;
	else
		len = ft_strlen(s);
	if (flag->min == 1)
	{
		write(1, s, len);
		ret += len;
		if (flag->star == 1)
			ret = ft_str_star(s, flag, ret);
	}
	else
	{
		if (flag->zero == 1)
			ret = ft_str_zero(s, flag, ret);
		else if (flag->star == 1)
			ret = ft_str_star(s, flag, ret);
		write(1, s, len);
		ret += len;
	}
	return (ret);
}

int	ft_str_null(t_printf *flag, int ret)
{
	if (flag->min == 1)
	{
		if (flag->prec < 0 || flag->prec >= 6 || flag->dot == 0)
			flag->prec = 6;
		write(1, "(null)", flag->prec);
		while ((flag->width)-- > flag->prec)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	else
	{
		if (flag->prec < 0 || flag->prec >= 6 || flag->dot == 0)
			flag->prec = 6;
		while ((flag->width)-- > flag->prec)
		{
			write(1, " ", 1);
			ret++;
		}
		write(1, "(null)", flag->prec);
	}
	return (ret + flag->prec);
}

int	ft_print_str(char *s, t_printf *flag, int ret)
{
	if (!s)
	{
		ret = ft_str_null(flag, ret);
		return (ret);
	}
	if (flag->prec >= ft_strlen(s) || flag->prec < 0)
		flag->prec = ft_strlen(s);
	ret = ft_is_str(s, flag, ret);
	return (ret);
}
