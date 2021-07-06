/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:06:36 by vcavalca          #+#    #+#             */
/*   Updated: 2021/07/06 14:05:20 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_zero(unsigned int num, t_printf *flag, int ret)
{
	int	temp;

	if (flag->dot == 1)
	{
		temp = flag->prec - ft_nbr_len(num, flag->type);
		while (temp-- > 0)
		{
			write(1, "0", 1);
			flag->width--;
			ret++;
		}
	}
	else
	{
		while ((flag->width)-- > ft_nbr_len(num, flag->type) + flag->nbr_m)
		{
			write(1, "0", 1);
			ret++;
		}
	}
	return (ret);
}

int	ft_print_star(unsigned int num, t_printf *flag, int ret)
{
	if (flag->dot == 1 && flag->prec > ft_nbr_len(num, flag->type))
	{
		while ((flag->width)-- > flag->prec + flag->nbr_m)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	else
	{
		while ((flag->width)-- > ft_nbr_len(num, flag->type) + flag->nbr_m)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	return (ret);
}

int	ft_nbr_len(unsigned long long n, char x)
{
	unsigned long long	base;
	int					len;

	len = 0;
	if (x == 'x' || x == 'X' || x == 'p')
		base = 16;
	else
		base = 10;
	while (n >= base)
	{
		len++;
		n = n / base;
	}
	len++;
	return (len);
}

void	ft_write_nbr(unsigned long long n, char x, unsigned int base)
{
	if (n >= base)
	{
		ft_write_nbr(n / base, x, base);
		ft_write_nbr(n % base, x, base);
	}
	else
	{
		if (x == 'x' || x == 'p')
			write(1, &"0123456789abcdef"[n % base], 1);
		else if (x == 'X')
			write(1, &"0123456789ABCDEF"[n % base], 1);
		else if (x == 'd' || x == 'i' || x == 'u')
			write(1, &"0123456789"[n % base], 1);
	}
}
