/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:06:39 by vcavalca          #+#    #+#             */
/*   Updated: 2021/07/06 14:42:16 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_char_star(t_printf *flag, int ret)
{
	if (flag->zero == 1)
	{
		while ((flag->width)-- > 1)
		{
			write(1, "0", 1);
			ret++;
		}
	}
	else
	{
		while ((flag->width)-- > 1)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	return (ret);
}

int	ft_print_char(int i, t_printf *flag, int ret)
{
	char	chr;

	chr = i;
	if (flag->min == 1 && flag->zero == 1)
		flag->zero = 0;
	if (flag->min == 1)
	{
		write(1, &chr, 1);
		ret++;
		if (flag->star == 1)
			ret = ft_char_star(flag, ret);
	}
	else
	{
		if (flag->star == 1)
			ret = ft_char_star(flag, ret);
		write(1, &chr, 1);
		ret++;
	}
	return (ret);
}
