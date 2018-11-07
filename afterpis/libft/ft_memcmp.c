/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:37:17 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/07 16:28:22 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *c_s1;
	unsigned char *c_s2;

	while (n-- > 0)
	{
		c_s1 = (unsigned char*)s1;
		c_s2 = (unsigned char*)s2;
		if (*c_s1 != *c_s2)
			return (*c_s1 - *c_s2);
	}
	return (0);
}
