/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:47:54 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 15:41:31 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
			return (NULL);
	if (*content != NULL)
	{
		new->content = (void*)content;
		new->content_size = content_size;
		new->next = NULL;
	}
	else
		ft_bzero(new, sizeof(t_list));
	return (new);
}
