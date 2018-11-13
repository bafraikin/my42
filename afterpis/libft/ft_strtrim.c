/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:20:24 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/13 23:09:11 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static	int		ft_ischarset(char const c)
{
	if (c != '\0' && (c == '\t' || c == '\n' || c == 32))
		return (1);
	return (0);
}

static	int		ft_count_word(char const *str)
{
	int count;

	if (str == NULL || !(*str))
		return (0);
	count = 0;
	while (*str != '\0')
	{
		if (!ft_ischarset(*str))
		{
			count++;
			while (!ft_ischarset(*str) && *str != '\0')
				str++;
		}
		if (*str)
			str++;
	}
	return (count);
}

static	size_t	my_strlen(char const *str)
{
	int i;
	int count;

	count = ft_count_word(str);
	i = 0;
	while (ft_ischarset(*str))
		str++;
	while (count > 0)
	{
		if (!ft_ischarset(str[i]))
		{
			count--;
			while (!ft_ischarset(str[i]) && str[i] != '\0')
				i++;
		}
		if (str[i] && count > 0)
			i++;
	}
	return ((size_t)i);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	int		i;

	if (!(s))
		return (NULL);
	i = my_strlen(s);
	if (!(new = ft_strnew(i)))
		return (NULL);
	while (ft_ischarset(*s))
		s++;
	new = ft_memcpy(new, s, i);
	new[i] = '\0';
	return (new);
}
