/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:56:46 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/12 16:05:22 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	i = -1;
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(s))))
		return (NULL);
	while (s[++i])
		new[i] = (*f)(i, s[i]);
	return (new);
}
