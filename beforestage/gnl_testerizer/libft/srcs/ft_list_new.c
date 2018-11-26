








#include "libft.h"
#include <stdlib.h>

t_list *ft_list_new(void  *content, size_t content_size)
{
  t_list  *new;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((void*)content != NULL)
	{
		new->content = content;
		new->content_size = content_size;
		new->next = NULL;
	}
	else
		ft_bzero(new, sizeof(t_list));
	return (new);
}
