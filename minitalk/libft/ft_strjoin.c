/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reuluyol <reuluyol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:47:23 by reuluyol          #+#    #+#             */
/*   Updated: 2024/11/03 11:35:36 by reuluyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s3 = (char *)malloc(i + j + 1);
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s1, i);
	ft_memcpy(s3 + i, s2, j);
	s3[i + j] = '\0';
	return (s3);
}
