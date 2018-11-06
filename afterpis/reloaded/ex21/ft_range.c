/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:27:50 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/05 18:59:12 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*res;
	int		i;

	i = 0;
	if (max <= min)
		return (NULL);
	res = (int*)malloc(sizeof(int) * (max - min));
	if (res == NULL)
		return (NULL);
	min--;
	while (++min < max)
		res[i++] = min;
	return (res);
}
