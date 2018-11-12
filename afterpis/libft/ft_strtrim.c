/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:20:24 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/12 19:47:57 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static	int		ft_ischarset(char c)
{
	if (c == '\t' || c == '\n' || c == 32)
		return (1);
	return (0);
}

static	size_t	my_strlen(char const *str)
{
	int i;

	i = -1;
	while (ft_ischarset(*str))
		str++;
	while (!ft_ischarset(str[++i]))
		;
	return ((size_t)i);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	int		i;

	i = my_strlen(s);
	if (!(new = ft_strnew(i + 1)))
		return (NULL);
	while (ft_ischarset(*s))
		s++;
	new = memcpy(new, s, i);
	return (new);
}
