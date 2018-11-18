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

int	get_next_line(const int fd,char **line)
{
  static t_list *begin;
  int ret;

  ret = 0;
  if (line && *line && fd > 0)
  while (ret = read(fd, *line, BUFF_SIZE))
  {


  }
  return (ret);
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
