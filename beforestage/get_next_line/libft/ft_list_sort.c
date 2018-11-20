/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:08:54 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 18:15:15 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	int		boolean;

	boolean = 1;
	while (boolean && (tmp = *begin_list) != NULL)
	{
		boolean = 0;
		while (tmp->next)
		{
			if ((*cmp)(tmp->content, tmp->next->content) > 0)
			{
				ft_swapptr(&(tmp->content), &(tmp->next->content));
				boolean = 1;
			}
			tmp = tmp->next;
		}
	}
}
