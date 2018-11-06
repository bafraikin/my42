/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:21:55 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/05 17:37:41 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str != '\0')
		ft_putchar(*(str++));
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2)
		return (0);
	while (++i < argc)
		ft_putstr(argv[i]);
	return (0);
}
