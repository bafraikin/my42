/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:46:26 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/27 15:44:17 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *content,
		size_t content_size)
{
	t_list *new;

	if (!(*begin_list))
	{
		*begin_list = ft_lstnew(content, content_size);
		return ;
	}
	new = *begin_list;
	while (new->next)
		new = new->next;
	new->next = ft_lstnew(content, content_size);
}
