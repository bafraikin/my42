/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:51:00 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/07 17:06:32 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int tmp;

	i = -1;
	if (!*needle)
		return (haystack);
	while (haystack[++i] != '\0' && (j = 0) == 0)
		if (haystack[i] == needle[j] && (tmp = i) >= 0)
			while (haystack[tmp] == needle[j] && needle[j])
			{
				tmp++;
				j++;
				 if (needle[j] == '\0')
					 return (&haystack[i]);
			}
	return (NULL);
}
