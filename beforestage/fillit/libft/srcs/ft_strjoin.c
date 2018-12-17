/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:07:39 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/20 16:25:07 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new;

	if (!(s1 && s2))
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
						ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcpy(new + ft_strlen(s1), s2);
	return (new);
}
