/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 22:13:24 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 18:11:44 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (nbr >= 1 && begin_list != 0)
	{
		begin_list = begin_list->next;
		nbr--;
	}
	if (nbr > 1)
		return (0);
	return (begin_list);
}
