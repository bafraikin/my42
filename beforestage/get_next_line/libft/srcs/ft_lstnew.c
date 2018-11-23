/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:47:54 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/23 19:04:10 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "../../get_next_line.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((void*)content != NULL)
	{
		new->content = ft_memalloc(content_size);
		ft_memcpy(new->content, content, content_size);
		printf("lst_new %d\n", ((t_fdlin*)content)->fd);
		printf("lst_new %d\n", ((t_fdlin*)new->content)->fd);
		printf("lst_new %lu\n", content_size);
		new->content_size = content_size;
		new->next = NULL;
	}
	else
		ft_bzero(new, sizeof(t_list));
	return (new);
}
