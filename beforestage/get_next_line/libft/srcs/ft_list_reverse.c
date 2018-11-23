/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:44:48 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 18:44:57 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list **begin_list)
{
	int		nb;
	t_list	*tmp;
	t_list	*buffer;
	t_list	*last;

	tmp = *begin_list;
	nb = 0;
	if (tmp && tmp->next)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
			nb++;
		}
		last = tmp;
		while (nb > 0)
		{
			buffer = ft_list_at(*begin_list, nb--);
			tmp->next = buffer;
			tmp = ft_list_at(*begin_list, nb--);
			buffer->next = tmp;
		}
		tmp->next = NULL;
		*begin_list = last;
	}
}
