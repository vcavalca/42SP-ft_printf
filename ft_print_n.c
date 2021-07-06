/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:06:34 by vcavalca          #+#    #+#             */
/*   Updated: 2021/07/06 13:36:21 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_n(t_printf *flag, int ret)
{
	if (flag->min == 1)
		return (ret);
	else if (flag->zero == 1)
	{
		while (flag->width-- > 1)
		{
			write(1, "0", 1);
			ret++;
		}
	}
	else
	{
		while (flag->width-- > 1)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	return (ret);
}
