/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:35:59 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/13 20:51:25 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	long	res;
	int		neg;

	neg = 0;
	res = 0;
	while (ft_is_space(*str))
		str++;
	if (*str == '-' && str++)
		neg = 1;
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (neg ? -res : res);
}
