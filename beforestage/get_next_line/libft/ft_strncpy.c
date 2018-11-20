/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:06:47 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/07 16:31:00 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = -1;
	while (src[++i] != '\0' && len > 0)
	{
		dst[i] = src[i];
		len--;
	}
	if (len > 0)
		while (len-- > 0)
			dst[i++] = '\0';
	return (dst);
}
