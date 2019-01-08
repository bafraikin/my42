/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:17:25 by salquier          #+#    #+#             */
/*   Updated: 2019/01/08 16:51:21 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void	ft_putnstr(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_print_grid(char **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putnstr(grid[i], size);
		ft_putchar('\n');
		i++;
	}
}

void	error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}
