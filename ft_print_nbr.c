/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:06:31 by vcavalca          #+#    #+#             */
/*   Updated: 2021/07/06 14:01:12 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nbr(unsigned int num, char x)
{
	char			nbr_index;
	unsigned int	base;

	if (x == 'x' || x == 'X' || x == 'p')
		base = 16;
	else
		base = 10;
	if (num >= base)
	{
		ft_nbr(num / base, x);
		ft_nbr(num % base, x);
	}
	else
	{
		if (x == 'x' || x == 'p')
			nbr_index = "0123456789abcdef"[num % base];
		else if (x == 'X')
			nbr_index = "0123456789ABCDEF"[num % base];
		else
			nbr_index = "0123456789"[num % base];
		write(1, &nbr_index, 1);
	}
}

int	ft_check_minus(t_printf *flag, int ret)
{
	if (flag->nbr_m == 1)
	{
		write(1, "-", 1);
		ret++;
	}
	return (ret);
}

int	ft_min_integer(t_printf *flag, int ret)
{
	flag->nbr_m = 1;
	ret = ft_print_x(flag, 2147483648, ret);
	return (ret);
}

int	ft_print_nbr(int n, t_printf *flag, int ret)
{
	if (flag->type == 'd' || flag->type == 'i')
	{
		if (n == -2147483648)
		{
			ret = ft_min_integer(flag, ret);
			return (ret);
		}
		if (n < 0)
		{
			flag->nbr_m = 1;
			n = -n;
		}
		ret = ft_print_x(flag, n, ret);
	}
	else
	{
		if (n < 0)
			ret = ft_print_x(flag, n + 4294967296, ret);
		else
			ret = ft_print_x(flag, n, ret);
	}
	return (ret);
}
