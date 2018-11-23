/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:15:47 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/23 19:01:13 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*mem;
	size_t	i;
	long	*cl_dst;
	long	*cl_src;

	i = 1;
	mem = dst;
	cl_dst = (long*)dst;
	cl_src = (long*)src;
	if ((unsigned int)src % 8 == 0 && (unsigned int)dst % 8 == 0)
		while (n / (i * 8) >= 1)
		{
			*cl_dst = *cl_src;
			cl_src++;
			cl_dst++;
			i++;
		}
	n = n - ((i - 1) * 8);
	if (i > 0 && (src = cl_src) != NULL)
		dst = cl_dst;
	while (n-- > 0)
		*(unsigned char*)(dst++) = *(unsigned char*)(src++);
	return (mem);
}
