/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:49:42 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 14:32:39 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int			ft_is_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static	int			ft_count_word(char const *str, char charset)
{
	int count;

	if (str == NULL || !(*str))
		return (0);
	count = 0;
	while (*str != '\0')
	{
		if (!ft_is_charset(*str, charset))
		{
			count++;
			while (!ft_is_charset(*str, charset) && *str != '\0')
				str++;
		}
		if (*str)
			str++;
	}
	return (count);
}

static const char	*ft_next_word(char const *str, char charset)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (!ft_is_charset(*str, charset))
			return (str);
		str++;
	}
	return (str);
}

static int			ft_lenght(char const *str, char charset)
{
	int index;

	index = 0;
	while (*str && !ft_is_charset(*str, charset))
	{
		index++;
		str++;
	}
	return (index);
}

char				**ft_strsplit(char const *s, char c)
{
	int		index;
	int		word_count;
	char	**split;
	int		lenght;
	int		j;

	if (!(s))
		return (0);
	index = -1;
	word_count = ft_count_word(s, c);
	if ((split = (char**)malloc(sizeof(char *) * (word_count + 1))) == NULL)
		return (0);
	s = ft_next_word(s, c);
	while (*s && (j = 0) == 0 && ++index < word_count)
	{
		lenght = ft_lenght(ft_next_word(s, c), c);
		if ((split[index] = (char *)malloc(sizeof(char) * (++lenght))) == NULL)
			return (0);
		while (--lenght > 0 && (split[index][j++] = *s) > 0)
			s++;
		split[index][j] = '\0';
		s = ft_next_word(s, c);
	}
	split[++index] = 0;
	return (split);
}
