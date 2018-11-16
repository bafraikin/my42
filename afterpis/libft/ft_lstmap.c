/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:27:16 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 18:45:15 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	tmp = lst;
	while (tmp)
	{
		if ((*f)(tmp) != NULL)
			ft_lstadd(&new, (*f)(tmp));
		else
			return (NULL);
		tmp = tmp->next;
	}
	ft_list_reverse(&new);
	return (new);
}
