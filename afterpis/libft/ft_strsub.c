/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:55:06 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/13 21:54:11 by bafraiki         ###   ########.fr       */
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
	if (!(ab = ft_strnew(len)))
		return (NULL);
	ab = ft_strncpy(ab, s + start, len);
	return (ab);
}
