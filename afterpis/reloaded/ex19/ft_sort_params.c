/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:35:42 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/05 18:13:00 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str != '\0')
		ft_putchar(*(str++));
	ft_putchar('\n');
}

void	ft_print_params(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2)
		return ;
	while (++i < argc)
		ft_putstr(argv[i]);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_swap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

int		main(int argc, char **argv)
{
	int i;
	int boolean;

	boolean = 1;
	if (argc < 2)
		return (0);
	while (boolean && (boolean = 0) == 0)
	{
		i = 1;
		while (++i < argc)
			if (ft_strcmp(argv[i], argv[i - 1]) < 0 && (boolean = 1) == 1)
				ft_swap(&argv[i], &argv[i - 1]);
	}
	ft_print_params(argc, argv);
	return (0);
}
