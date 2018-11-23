/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:37:12 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 16:54:15 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tmp2;

	if (alst && *alst && del)
	{
		tmp = *alst;
		while (tmp)
		{
			del(tmp->content, tmp->content_size);
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
		}
		*alst = NULL;
	}
}
