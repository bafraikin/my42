/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:10:31 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/04 17:40:41 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_letter	*ft_new_letter(char c)
{
	t_letter *new;
	if ((new = (t_letter*)malloc(sizeof(t_letter))) == NULL)
		exit(EXIT_FAILURE);
	new->letter = c;
	new->next = NULL;
	return (new);
}

void	add_new_letter(t_letter **begin, char c)
{
	t_letter *elem;
	t_letter *tmp;

	if (!*begin)
	{
		*begin = ft_new_letter(c);
		return ;
	}
	elem = *begin;
	while (elem->next && elem->letter <= c)
		if (elem->letter == c || elem->next->letter == c) //not especially necessary but for dev we must be prudent
			return ;
		else
			elem = elem->next;
	if (elem->next)
	{
		tmp = elem->next;
		elem->next = ft_new_letter(c);
		elem->next->next = tmp;
	}
	else
		elem->next = ft_new_letter(c);
}

char	remove_letter(t_letter **begin, char c)
{
	t_letter *elem;
	t_letter *tmp;

	elem = *begin;
	if (elem->letter == c && elem->next && (*begin = elem->next) != NULL)
	{
		free(elem);
		return (c);
	}
	while (elem->next && elem->next->letter != c)
		elem = elem->next;
	if (elem->next && elem->next->letter == c && (tmp = elem->next) != NULL)
	{
		elem->next = elem->next->next;
		free(tmp);
	}
	else if (elem->letter == c && (*begin = NULL) == NULL)
		free(elem);
	else if (elem->next->letter == c)
	{
		free(elem->next);
		elem->next = NULL;
	}
	return (c);
}


