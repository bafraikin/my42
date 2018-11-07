/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:38:00 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/07 16:26:52 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	size_t	val;

	val = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	j = -1;
	while (size-- > 0 && dst[i] != '\0')
		i++;
	while (size-- > 0 && src[++j] != '\0')
	{
		dst[i] = src[j];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	else
		dst[i - 1] = '\0';
	return (val);
}
