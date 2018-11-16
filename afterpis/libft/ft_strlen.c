/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:46:47 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 22:33:56 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i + 1] == '\0')
			return (i + 1);
		else if (s[i + 2] == '\0')
			return (i + 2);
		else if (s[i + 3] == '\0')
			return (i + 3);
		else if (s[i + 4] == '\0')
			return (i + 4);
		i += 4;
	}
	return (i);
}
