/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:27:53 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/13 23:02:21 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *c_s;

	while (n-- > 0)
	{
		c_s = (unsigned char*)s;
		if (*c_s == (unsigned char)c)
			return ((void*)s);
		s++;
	}
	return (NULL);
}
