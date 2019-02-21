/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:43:32 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/12 14:08:17 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_c;
	char	*tmp;

	tmp = NULL;
	c_c = (char)c;
	while (*s != '\0')
	{
		if (c_c == *s)
			tmp = (char*)s;
		s++;
	}
	if (c_c == '\0')
		tmp = (char*)s;
	return (tmp);
}
