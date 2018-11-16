/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:06:07 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 20:13:26 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > sizeof(long) && (n -= sizeof(long)) > 0)
	{
		*(long*)s = 0;
		s = s + sizeof(long);
	}
	while (n > sizeof(int) && (n -= sizeof(int)) > 0)
	{
		*(int*)s = 0;
		s = s + sizeof(int);
	}
	while (n-- > 0)
		*(unsigned char*)(s++) = 0;
}
