/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reuluyol <reuluyol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:24:28 by reuluyol          #+#    #+#             */
/*   Updated: 2024/11/03 12:19:52 by reuluyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countmem(int n, int sign)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	if (sign < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	int		sign;
	int		countmem;

	number = n;
	sign = 1;
	if (number < 0)
		sign = -1;
	number = sign * number;
	countmem = ft_countmem(number, sign);
	str = (char *)malloc(sizeof(char) * (countmem + 1));
	if (str == NULL)
		return (NULL);
	str[countmem] = '\0';
	while (countmem > 0)
	{
		str[--countmem] = (number % 10) + '0';
		number = number / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
