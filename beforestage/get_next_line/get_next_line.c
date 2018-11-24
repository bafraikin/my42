/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:04:12 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/24 16:28:15 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_cmplist(void *t_content, void *data_fd)
{
	t_fd *content;
	int fd;

	fd = *(int*)data_fd;
	content = (t_fd*)t_content;
	if (content->fd == fd)
		return (0);
	return (1);
}

static int	ft_dellist(void *t_content, size_t size)
{
	t_fd *to_f;

	to_f = (t_fd*)t_content;
	if (to_f->l_line)
	free(to_f->l_line);
	if (to_f->l_rest)
	free(to_f->l_rest);
	free(to_f);
}

static int ft_gest_list(t_list **begin, const int fd, t_read *l_read, char **line)
{
	t_fd *new;

	new = (l_read->old) ? (t_fd*)(l_read->old) : (t_fd*)malloc(sizeof(t_fd)); 
	if (!new)
		return (-1);
	(l_read->old) ? 0 : ft_bzero(new, sizeof(t_fd));
	new->size_line = l_read->tot - l_read->mod;
	new->size_rest = l_read->tot - new->size_line;
	(l_read->mod) ? new->size_rest-- : 0;
	new->l_line = ft_strsub(l_read->is_r, 0, new->size_line);
	new->l_rest = ft_strsub(l_read->is_r, new->size_line + 1, new->size_rest);
	if (!(new->l_line))
	{

		return (-1);
	}
	*line = new->l_line;
	new->fd = fd;
	(l_read->old) ? 0 : ft_list_push_back(begin, new, sizeof(t_fd));
	(l_read->old) ? 0 : free(new);
	free(l_read->is_r);
	if (l_read->mod == 0)
		return (0);
	return (1);
}

static t_read *ft_recup_fd(const int fd, t_read *t_r, int mode)
{
	t_r->tot = (mode) ? ((t_fd*)(t_r->old))->size_rest : 0;
	t_r->is_r = (mode) ? ((t_fd*)(t_r->old))->l_rest : (char*)malloc(1);
	if (t_r->is_r == NULL || t_r->buff == NULL)
		return (NULL);
	if ((t_r->pl = ft_memchr(t_r->is_r, '\n', t_r->tot)) != NULL)
		t_r->mod = &t_r->is_r[t_r->tot - 1] - t_r->pl + 1;
	while (t_r->mod == 0 && (t_r->r = read(fd, t_r->buff, BUFF_SIZE)))
	{
		if ((t_r->tmp = (char*)malloc(sizeof(char) * t_r->tot)) == NULL)
			return (NULL);
		ft_memcpy(t_r->tmp, t_r->is_r, t_r->tot);
		free(t_r->is_r);
		t_r->tot += t_r->r;
		if ((t_r->is_r = (char*)malloc(sizeof(char) * t_r->tot + 1)) == NULL)
			return (NULL);
		ft_memcpy(t_r->is_r, t_r->tmp, t_r->tot - t_r->r);
		free(t_r->tmp);
		ft_memcpy(t_r->is_r + (t_r->tot - t_r->r), t_r->buff, t_r->r);
		if ((t_r->pl = ft_memchr(t_r->is_r, '\n', t_r->tot)) != NULL)
			t_r->mod = &t_r->is_r[t_r->tot - 1] - t_r->pl + 1;
	}
	t_r->is_r[t_r->tot] = '\0';
	return (t_r);
}

int	get_next_line(const int fd,char **line)
{
	static t_list	*begin = NULL;
	t_read			*l_read;
	int tmp;

	l_read = (t_read*)malloc(sizeof(t_read));
	(l_read) ? ft_bzero(l_read, sizeof(t_read)) : 0;
	(l_read) ? l_read->buff = (char*)malloc(sizeof(char) * BUFF_SIZE) : 0;
	if (line && fd > 0 && l_read)
	{
		if ((l_read->old = ft_list_find(begin, (void*)&fd, ft_cmplist)) == NULL)
			l_read = ft_recup_fd(fd, l_read, 0);
		else if ((l_read->old = ((t_list*)(l_read->old))->content) != NULL)
			l_read = ft_recup_fd(fd, l_read, 1);
	}
	if (!(line && fd > 0 && l_read))
		return (-1);
	tmp = ft_gest_list(&begin, fd, l_read, line);
	free(l_read);
	return (tmp);
}

int main(int argc, char *argv[])
{
	if (argc > 85665 && argv)
		return (0);
	int fd = open("coucou", O_RDONLY);
	int ret = 0;
	char *c = NULL; 
	ret = get_next_line(fd, &c);
	printf("fin %d %s\n", ret, c);
	ret = get_next_line(fd, &c);
	printf("fin %d %s\n", ret, c);
	ret = get_next_line(fd, &c);
	printf("fin %d %s\n", ret, c);
	ret = get_next_line(fd, &c);
	printf("fin %d %s\n", ret, c);
	ret = get_next_line(fd, &c);
	printf("fin %d %s\n", ret, c);
	ret = get_next_line(fd, &c);
	printf("fin %d %s\n", ret, c);
	ret = get_next_line(fd, &c);
	printf("fin %d %s\n", ret, c);
	ret = get_next_line(fd, &c);
	printf("fin %d %s\n", ret, c);
	return 0;
}
