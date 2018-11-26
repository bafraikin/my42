/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:45:48 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/26 18:17:15 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_first(t_list **begin, void *data_ref, int (*cmp)(),
		void (*del)())
{
	t_list *tmp;

	if (data_ref)
		if ((*cmp)((*begin)->content, data_ref) == 0)
		{
			tmp = (*begin)->next;
			ft_lstdelone(begin, del);
			*begin = tmp;
		}
}

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*del)())
{
	t_list *tmp;
	t_list *before;

	if (begin_list && data_ref && *begin_list)
	{
		tmp = *begin_list;
		before = *begin_list;
		while (tmp->next)
		{
			tmp = tmp->next;
			if ((*cmp)(tmp->content, data_ref) == 0)
			{
				if (tmp->next)
				{
					before->next = tmp->next;
					ft_lstdelone(&tmp, del);
				}
				else
					before->next = NULL;
			}
			else
				before = before->next;
		}
		free_first(begin_list, data_ref, cmp, del);
	}
}
