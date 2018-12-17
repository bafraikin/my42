/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:33:14 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/13 21:06:59 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fiill(char *str, char c)
{
	while (*str)
		str++;
	*str = c;
}

static size_t	ft_intlen(int nb)
{
	int range;
	int i;

	i = 9;
	range = 1000000000;
	while (nb / range == 0 && i-- > 0)
		range /= 10;
	return (i);
}

char			*ft_itoa(int n)
{
	int		range;
	long	nb_long;
	char	*str;
	char	boolean;

	if ((str = ft_strnew(ft_intlen(n) + 2)) == NULL)
		return (NULL);
	nb_long = n;
	if ((range = 1000000000) > 0 && n == 0)
	{
		ft_fiill(str, '0');
		return (str);
	}
	if ((boolean = 0) == 0 && n < 0)
		ft_fiill(str, '-');
	nb_long = n < 0 ? -nb_long : nb_long;
	while (range > 0)
	{
		n = (nb_long / range) % 10;
		if ((boolean || n) && (boolean = 1) == 1)
			ft_fiill(str, n + '0');
		range = range / 10;
	}
	return (str);
}
