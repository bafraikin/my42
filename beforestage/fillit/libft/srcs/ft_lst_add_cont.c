/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:35:32 by bafraiki          #+#    #+#             */
/*   Updated: 2018/12/03 11:36:04 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_add_cont(void *content, size_t content_size)
{
	t_list *new;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->content = content;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
