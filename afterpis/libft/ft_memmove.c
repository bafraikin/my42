/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:14:38 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/13 16:39:52 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;
	void			*mem;
	void			*save;

	mem = dst;
	save = malloc(sizeof(void) * (len + 1));
	if (save == NULL)
		return (NULL);
	save = ft_memcpy(save, src, len);
	while (len-- > 0)
	{
		c_dst = (unsigned char *)dst;
		c_src = (unsigned char *)save;
		*c_dst = *c_src;
		dst++;
		save++;
	}
	return (mem);
}
