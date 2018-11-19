/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:06:07 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/19 18:33:04 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	long			*cl_s;
	unsigned char	*cc_s;

	i = 1;
	cl_s = NULL;
	if ((unsigned int)s % sizeof(long) == 0)
	{
		cl_s = s;
		while (n / (i * 8) >= 1)
			*(cl_s++) = 0;
		n = n - (i * 8);
	}
	cc_s = (cl_s == NULL) ? (unsigned char*)s : (unsigned char*)cl_s;
	if (n > 0)
		while (n-- > 0)
			*(cc_s++) = 0;
}
