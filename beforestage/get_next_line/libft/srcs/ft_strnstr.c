/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:09:05 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/13 18:22:38 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;
	int tmp;

	i = -1;
	if (!*needle)
		return ((char*)haystack);
	while ((int)len-- >= 0 && haystack[++i] != '\0' && (j = 0) == 0)
		if (haystack[i] == needle[j] && (tmp = i) >= 0)
			while (haystack[tmp] == needle[j] && ((int)len - j) >= 0)
			{
				tmp++;
				j++;
				if (needle[j] == '\0')
					return ((char*)&haystack[i]);
			}
	return (NULL);
}
