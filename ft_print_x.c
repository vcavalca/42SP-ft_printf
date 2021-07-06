/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:06:23 by vcavalca          #+#    #+#             */
/*   Updated: 2021/07/06 14:08:00 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_left(unsigned int num, t_printf *flag, int ret)
{
	int	temp;
	int	len;

	len = ft_nbr_len(num, flag->type) + flag->nbr_m;
	ret = ft_check_minus(flag, ret);
	if (flag->prec >= ft_nbr_len(num, flag->type) + flag->nbr_m)
	{
		temp = flag->prec - ft_nbr_len(num, flag->type);
		while (temp-- > 0)
		{
			write(1, "0", 1);
			len++;
			ret++;
		}
	}
	ft_nbr(num, flag->type);
	ret += ft_nbr_len(num, flag->type);
	while ((flag->width)-- > len)
	{
		write(1, " ", 1);
		ret++;
	}
	return (ret);
}

int	ft_print_right(unsigned int num, t_printf *flag, int ret)
{
	char	type;

	type = flag->type;
	ret = ft_print_star(num, flag, ret);
	ret = ft_check_minus(flag, ret);
	if (flag->dot == 1 && flag->prec >= ft_nbr_len(num, type) + flag->nbr_m)
		ret = ft_print_zero(num, flag, ret);
	ft_nbr(num, type);
	ret += ft_nbr_len(num, type);
	return (ret);
}

int	ft_is_dot(unsigned int num, t_printf *flag, int ret)
{
	if (flag->min == 1)
		ret = ft_print_left(num, flag, ret);
	else
		ret = ft_print_right(num, flag, ret);
	return (ret);
}

int	ft_not_dot(unsigned int num, t_printf *flag, int ret)
{
	if (flag->min == 1)
	{
		ret = ft_check_minus(flag, ret);
		ft_nbr(num, flag->type);
		ret += ft_nbr_len(num, flag->type);
		ret = ft_print_star(num, flag, ret);
	}
	else if (flag->zero == 1)
	{
		ret = ft_check_minus(flag, ret);
		ret = ft_print_zero(num, flag, ret);
		ft_nbr(num, flag->type);
		ret += ft_nbr_len(num, flag->type);
	}
	else
		ret = ft_print_right(num, flag, ret);
	return (ret);
}

int	ft_print_x(t_printf *flag, unsigned int num, int ret)
{
	if (flag->prec < 0)
		flag->dot = 0;
	if (flag->dot == 1 && flag->prec == 0 && num == 0)
	{
		while ((flag->width)-- > 0)
		{
			write(1, " ", 1);
			ret++;
		}
		return (ret);
	}
	if (flag->zero == 1 && flag->dot == 1)
		flag->zero = 0;
	else if (flag->zero == 1 && flag->dot == 0 && flag->min == 1)
		flag->zero = 0;
	if (flag->dot == 1)
		ret = ft_is_dot(num, flag, ret);
	else
		ret = ft_not_dot(num, flag, ret);
	return (ret);
}
