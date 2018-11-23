/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:06:07 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/19 13:05:26 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	long			*cl_s;
	unsigned char	*cc_s;

	i = 0;
	cc_s = NULL;
	if (n % sizeof(long) != 0)
	{
		cc_s = s;
		while (n % sizeof(long) != 0 && n-- > 0)
			*(cc_s++) = 0;
	}
	cl_s = (cc_s == NULL) ? (long*)s : (long*)cc_s;
	if (n > 0)
		while (i < n / sizeof(long))
		{
			*cl_s = 0;
			cl_s++;
			i++;
		}
}
