/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:05:04 by bafraiki          #+#    #+#             */
/*   Updated: 2018/12/03 11:36:32 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_add_back(t_list **begin_list, void *content,
		size_t content_size)
{
	t_list	*new;

	if (!(*begin_list))
	{
		*begin_list = ft_lst_add_cont(content, content_size);
		return ;
	}
	new = *begin_list;
	while (new->next)
		new = new->next;
	new->next = ft_lst_add_cont(content, content_size);
}
