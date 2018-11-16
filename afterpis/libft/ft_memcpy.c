/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:15:47 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 20:22:59 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *mem;

	mem = dst;
	while (n > sizeof(long) && (n -= sizeof(long)) > 0)
	{
		*(long*)dst = *(long*)src;
		dst += sizeof(long);
		src += sizeof(long);
	}
	while (n > sizeof(int) && (n -= sizeof(int)) > 0)
	{
		*(int*)dst = *(int*)src;
		dst += sizeof(int);
		src += sizeof(int);
	}
	while (n-- > 0)
		*(char*)(dst++) = *(char*)(src++);
	return (mem);
}
