/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reuluyol <reuluyol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 07:25:19 by reuluyol          #+#    #+#             */
/*   Updated: 2024/12/08 18:10:55 by reuluyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_str(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_is_int(int a)
{
	int	ret;

	ret = 0;
	if (a == 0)
		return (write(1, "0", 1));
	if (a == -2147483648)
		return (write(1, "-2147483648", 11));
	if (a < 0)
	{
		ret += write(1, "-", 1);
		a *= -1;
	}
	if (a >= 10)
		ret += ft_is_int(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (ret + 1);
}

int	ft_is_unsigned(unsigned int x)
{
	int	ret;

	ret = 0;
	if (x >= 10)
		ret += ft_is_unsigned(x / 10);
	write(1, &"0123456789"[x % 10], 1);
	return (ret + 1);
}

int	ft_is_hex(unsigned int x, char c)
{
	int	ret;

	ret = 0;
	if (x >= 16)
		ret += ft_is_hex(x / 16, c);
	if (c == 'x')
		write(1, &"0123456789abcdef"[x % 16], 1);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[x % 16], 1);
	return (ret + 1);
}

int	ft_is_pointer(unsigned long x, int sign)
{
	int	ret;

	ret = 0;
	if (!x)
		return (write(1, "(nil)", 5));
	if (sign == 1)
	{
		ret += write(1, "0x", 2);
		sign = 0;
	}
	if (x >= 16)
		ret += ft_is_pointer(x / 16, 0);
	write(1, &"0123456789abcdef"[x % 16], 1);
	return (ret + 1);
}
