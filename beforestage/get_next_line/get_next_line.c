/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:04:12 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/20 18:07:50 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_cmplist(void *t_content, void *data_fd)
{
	t_fdlin *content;
	int fd;

	fd = *(int*)data_fd;
	content = (t_fdlin*)t_content;
	if (content->fd == fd)
		return (0);
	return (1);
}

static int ft_gest_list(t_list **begin, const int fd, t_read *l_read)
{
	t_fdlin *new;

	if ((new = (t_fdlin*)malloc(sizeof(t_fdlin))) == NULL)
		return (0);
	ft_bzero(new, sizeof(t_fdlin));
	new->size_line = l_read->tot - l_read->mod;
	new->size_rest = l_read->tot - new->size_line;
	new->l_line = ft_strsub(l_read->is_r, 0, new->size_line);
	new->l_rest = ft_strsub(l_read->is_r, new->size_line, new->size_rest);
	if (!(new->l_line && new->l_rest))
		return (0);
	if (l_read->mod == 0)
		new->mode = 0;
	else
		new->mode = 1;
	new->fd = fd;
	ft_list_push_back(begin, new, fd);
	free(l_read->is_r);
	return (1);
}

static t_read *ft_recup_fd(const int fd, t_read *t_r, int mode)
{
	t_r->is_r = (mode) ? t_r->old->l_rest : NULL;
	t_r->tot = (mode) ? t_r->old->size_rest : 0;
	t_r->pl = (mode) ? t_r->old->l_rest : NULL;
	t_r->buff = (char*)malloc((char) * BUFF_SIZE);
	if ((t_r->is_r = (char*)malloc(1)) == NULL || t_r->buff == NULL)
		return (NULL);
	while (t_r->pl || (t_r->mod == 0 &&
				(t_r->r = read(fd, t_r->buff, BUFF_SIZE))))
	{
		if ((t_r->tmp = (char*)malloc(sizeof(char) * t_r->tot)) == NULL)
			return (NULL);
		ft_memcpy(t_r->tmp, t_r->is_r, t_r->tot);
		t_r->tot += t_r->r;
		free(t_r->is_r);
		if ((t_r->pl = ft_memchr(t_r->buff, '\n', t_r->r)) != NULL)
			t_r->mod = &t_r->buff[t_r->r - 1] - t_r->pl;
		if ((t_r->is_r = (char*)malloc(sizeof(char) * t_r->tot + 1)) == NULL)
			return (NULL);
		ft_memcpy(t_r->is_r, t_r->tmp, t_r->tot - t_r->r);
		free(t_r->tmp);
		ft_memcpy(t_r->is_r + (t_r->tot - t_r->r), t_r->buff, t_r->r);
	}
	t_r->is_r[t_r->tot] = '\0';
	return (t_r);
}

int	get_next_line(const int fd,char **line)
{
	static t_list	*begin = NULL;
	t_read			*l_read;

	l_read = (t_read*)malloc(sizeof(t_read));
	(l_read) ? ft_bzero(l_read, sizeof(t_read)) : 0;
	if (line && *line && fd > 0 && l_read)
		if ((l_read->old = ft_list_find(begin, fd, ft_cmplist)) == NULL)
			l_read = ft_recup_fd(fd, l_read, 0);
		else
			l_read = ft_recup_fd(fd, l_read, 1);
	if (!(line && *line && fd > 0 && l_read))
		return (-1);
	ft_gest_list(&begin, fd, l_read);
	//FREE t_read
	return (1);
}

int main(int argc, char *argv[])
{
	if (argc > 856654)
		return (0);
	int fd = open("coucou", O_RDONLY);
	int ret = 0;
	char *c = (char*)malloc(sizeof(char) *(BUFF_SIZE + 1));
	ret = get_next_line(fd, &c);
	printf("%s\n", c);
	return 0;
}
