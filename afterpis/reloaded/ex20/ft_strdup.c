/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:16:14 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/05 18:27:07 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int nb;

	nb = 0;
	while (*(str++) != '\0')
		nb++;
	return (nb);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = -1;
	dup = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dup == NULL)
		return (NULL);
	while (src[++i] != '\0')
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}
