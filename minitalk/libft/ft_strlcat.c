/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reuluyol <reuluyol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:31:48 by reuluyol          #+#    #+#             */
/*   Updated: 2024/11/03 15:15:58 by reuluyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t sz)
{
	size_t	i;

	i = ft_strlen(dst) + ft_strlen(src);
	if (sz <= ft_strlen(dst))
		return (sz + ft_strlen(src));
	ft_strlcpy (dst + ft_strlen(dst), src, sz - ft_strlen(dst));
	return (i);
}
