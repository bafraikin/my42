/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:04:12 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 14:43:00 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void *ft_gest_list(t_list **begin, int ret, const int fd, char *line)
{
  /*
     int       ret;
     int       total;
     int       mode;
     char      *t_rd->ptr_line;
     char      *t_rd->is_read;
     char      *tmp;
     */


}

static t_read *ft_recup_fd(const int fd, char *line)
{
  t_read  *t_rd;

  if (!(line && fd > 0))
    return (NULL);
  t_rd = (t_read*)malloc(sizeof(t_read));
  ft_bzero(t_rd, sizeof(t_read));
  t_rd->is_read = (char*)malloc(1);
  if t_rd
    while (t_rd->mode == 0 && (t_rd->ret = read(fd, *line, BUFF_SIZE)))
    {
      if ((t_rd->tmp = (char*)malloc(sizeof(char) * t_rd->total)) == NULL)
        return (NULL);
      ft_memcpy(t_rd->tmp, t_rd->is_read, t_rd->total);
      t_rd->total += t_rd->ret;
      free(t_rd->is_read);
      if ((t_rd->ptr_line = ft_memchr(*line, '\n', t_rd->ret)) != NULL)
        mode = 1;
      if ((t_rd->is_read = (char*)malloc(sizeof(char) * t_rd->total + 1)) == NULL)
        return (NULL);
      ft_memcpy(t_rd->is_read, t_rd->tmp, t_rd->total - t_rd->ret);
      free(t_rd->tmp);
      ft_memcpy(t_rd->is_read + (t_rd->total - t_rd->ret), line, t_rd->ret);
    }
  t_rd->is_read[total] = '\0';
  return (t_rd);
}

int	get_next_line(const int fd,char **line)
{
  static t_list *begin = NULL;
  t_read  *l_read;  

  l_read = NULL;
  if (line && *line && fd > 0)
    l_read = ft_recup_fd(fd, *line);
  if (!(line && *line && fd > 0 && l_read))
    return (-1);

  return (1)
}

int main(int argc, char *argv[])
{
  int fd = open("coucou", O_RDONLY);
  int ret = 0;
  char *c = (char*)malloc(sizeof(char) *(BUFF_SIZE + 1));
  ret = get_next_line(fd, &c);
  printf("%s\n", c);
  return 0;
}
