/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:10:14 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/13 16:11:32 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	int		range;
	long	nb_long;
	char	boolean;

	nb_long = nb;
	boolean = 0;
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (nb < 0)
		ft_putchar_fd('-', fd);
	nb_long = nb < 0 ? -nb_long : nb_long;
	range = 1000000000;
	while (range > 0)
	{
		nb = (nb_long / range) % 10;
		if (boolean || nb)
		{
			ft_putchar_fd(nb + '0', fd);
			boolean = 1;
		}
		range = range / 10;
	}
}
