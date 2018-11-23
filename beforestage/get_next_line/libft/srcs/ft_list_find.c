/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:37:29 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/23 18:52:42 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;

	tmp = begin_list;
	if (begin_list)
	{
		while (tmp)
		{
			if ((*cmp)(tmp->content, data_ref) == 0)
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (NULL);
}
