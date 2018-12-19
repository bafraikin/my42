/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:25:25 by bafraiki          #+#    #+#             */
/*   Updated: 2018/12/19 14:42:29 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_add_value(char **form, i, j)
{
	form[0][0] = i;
	form[0][1] = j;
}

int ft_check_fill(char **grid)
{
	int		i;
	int		j;
	int 	k;
	int		lm[2];
	char	form[4][2];

	i = -1;
	lm[0] = 0;
	lm[1] = 0;
	k = 0;
	ft_add_value(form[k++], 0, 0);
	while(grid[++i] && *grid[i] && (j = -1) < 0)
		while (++j < 4)
			if (grid[i][j] == '#' && lm[0] == 0 && (lm[0] = i) >= 0)
				lm[1] = j;
			else if (grid[i][j] == '#')
				ft_add_value(&form[k++], lm[0] - i, lm[1] - j);
}
