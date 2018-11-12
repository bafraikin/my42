/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:38:49 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/12 15:58:05 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	i = -1;
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(s))))
		return (NULL);
	while (s[++i])
		new[i] = (*f)(s[i]);
	return (new);
}
