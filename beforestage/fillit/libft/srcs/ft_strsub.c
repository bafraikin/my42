/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:55:06 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/19 19:08:19 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ab;

	if (!(s && *s))
		return (NULL);
	if (!(ab = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ab[len] = '\0';
	ab = ft_memcpy(ab, s + start, len);
	return (ab);
}
