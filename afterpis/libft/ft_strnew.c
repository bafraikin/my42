/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:09:11 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/12 15:17:23 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new;

	if (!(new = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	ft_memset(new, 0, size);
	return (new);
}
