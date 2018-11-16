/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:27:16 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 22:18:24 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;
	t_list *ret;

	tmp = lst;
	if (lst && f)
	{
		while (tmp)
		{
			ret = (*f)(tmp);
			if ((ret = ft_lstnew(ret->content, ret->content_size)) == NULL)
				return (NULL);
			ft_lstadd(&new, ret);
			tmp = tmp->next;
		}
		ft_list_reverse(&new->next);
		return (new);
	}
	return (NULL);
}
