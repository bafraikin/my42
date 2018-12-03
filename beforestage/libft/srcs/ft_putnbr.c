/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:05:04 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/13 16:25:17 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int		range;
	long	nb_long;
	char	boolean;

	nb_long = nb;
	boolean = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (nb < 0)
		ft_putchar('-');
	nb_long = nb < 0 ? -nb_long : nb_long;
	range = 1000000000;
	while (range > 0)
	{
		nb = (nb_long / range) % 10;
		if (boolean || nb)
		{
			ft_putchar(nb + '0');
			boolean = 1;
		}
		range = range / 10;
	}
}
