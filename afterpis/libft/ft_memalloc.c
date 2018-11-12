/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:54:30 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/12 15:03:22 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *new;

	if (!(new = malloc(sizeof(void) * size)))
		return (NULL);
	ft_memset(new, 0, size);
	return (new);
}
