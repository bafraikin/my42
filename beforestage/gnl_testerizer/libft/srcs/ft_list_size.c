/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 19:17:21 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 18:12:46 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list *begin_list)
{
	int		index;
	t_list	*list;

	index = (begin_list) ? 1 : 0;
	list = begin_list;
	if (index)
		while (list->next)
		{
			index++;
			list = list->next;
		}
	return (index);
}
