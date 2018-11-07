/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:43:32 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/07 17:08:03 by bafraiki         ###   ########.fr       */
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
			tmp = s;
		s++;
	}
	return (tmp);
}
