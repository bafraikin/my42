/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:10:14 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/13 16:30:40 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		range;
	long	nb_long;
	char	boolean;

	nb_long = n;
	boolean = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	nb_long = n < 0 ? -nb_long : nb_long;
	range = 1000000000;
	while (range > 0)
	{
		n = (nb_long / range) % 10;
		if (boolean || n)
		{
			ft_putchar_fd(n + '0', fd);
			boolean = 1;
		}
		range = range / 10;
	}
}
