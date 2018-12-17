/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:27:16 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 22:54:57 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;
	t_list *ret;

	tmp = lst;
	new = NULL;
	if (lst && f)
	{
		while (tmp)
		{
			ret = (*f)(tmp);
			ft_list_push_back(&new, ret->content, ret->content_size);
			tmp = tmp->next;
		}
		return (new);
	}
	return (NULL);
}
