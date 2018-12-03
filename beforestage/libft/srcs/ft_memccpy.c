/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:42:02 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 22:12:58 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;

	while (n-- > 0)
	{
		c_dst = (unsigned char *)dst;
		c_src = (unsigned char *)src;
		if (*c_src == (unsigned char)c)
		{
			*(unsigned char *)dst = (unsigned char)c;
			return (++dst);
		}
		*c_dst = *c_src;
		dst++;
		src++;
	}
	return (NULL);
}
