/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:06:28 by vcavalca          #+#    #+#             */
/*   Updated: 2021/07/06 14:11:40 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_star(t_printf *flag, unsigned long long num, int ret)
{
	int	len;

	if (flag->dot == 1 && flag->prec == 0 && num == 0)
		len = 0;
	else
		len = ft_nbr_len(num, flag->type);
	while ((flag->width)-- > (len + 2))
	{
		write(1, " ", 1);
		ret++;
	}
	return (ret);
}

int	ft_p_left(t_printf *flag, unsigned long long num, int ret)
{
	write(1, "0x", 2);
	ret += 2;
	if (!(flag->dot == 1 && flag->prec == 0 && num == 0))
	{
		ft_write_nbr(num, flag->type, 16);
		ret += ft_nbr_len(num, flag->type);
	}
	if (flag->star == 1)
		ret = ft_p_star(flag, num, ret);
	return (ret);
}

int	ft_p_right(t_printf *flag, unsigned long long num, int ret)
{
	if (flag->star == 1)
		ret = ft_p_star(flag, num, ret);
	write(1, "0x", 2);
	ret += 2;
	while (flag->prec > ft_nbr_len(num, flag->type))
	{
		flag->prec--;
		write(1, "0", 1);
		ret++;
	}
	if (!(flag->dot == 1 && flag->prec == 0 && num == 0))
	{
		ft_write_nbr(num, flag->type, 16);
		ret += ft_nbr_len(num, flag->type);
	}
	return (ret);
}

int	ft_print_p(t_printf *flag, unsigned long long num, int ret)
{
	if (flag->min == 1)
		ret = ft_p_left(flag, num, ret);
	else
		ret = ft_p_right(flag, num, ret);
	return (ret);
}
