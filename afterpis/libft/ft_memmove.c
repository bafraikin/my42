/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:14:38 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/06 20:38:13 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *c_dst;
	unsigned char *c_src;

	while (len-- > 0)
	{
		c_dst = (unsigned char *)dst;
		c_src = (unsigned char *)src;
		*c_dst = *c_src;
		dst++;
		src++;
	}
	return (NULL);
}
