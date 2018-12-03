/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:45:48 by bafraiki          #+#    #+#             */
/*   Updated: 2018/12/03 11:03:40 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*del)())
{
	t_list	*tmp;
	t_list	*i;

	while (*begin_list && cmp((*begin_list)->content, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		ft_lstdelone(&tmp, del);
	}
	i = *begin_list;
	while (i && i->next)
	{
		if (cmp(i->next->content, data_ref) == 0)
		{
			tmp = i->next;
			i->next = tmp->next;
			ft_lstdelone(&tmp, del);
		}
		if (i->next)
			i = i->next;
	}
}
