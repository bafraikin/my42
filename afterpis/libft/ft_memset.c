/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:22:37 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 15:31:18 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*mem;

	mem = b;
	while (len-- > 0)
	{
		*(unsigned char *)b = (unsigned char)c;
		b++;
	}
	return (mem);
}
