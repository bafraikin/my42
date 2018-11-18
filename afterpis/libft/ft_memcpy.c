/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:15:47 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/16 22:15:36 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
  void *mem;
  size_t i;
  long *cl_dst;
  long *cl_src;

  i = 0;
  mem = dst;
  if (n % sizeof(long) != 0)
    while (n % sizeof(long) != 0 && n-- > 0)
      *(unsigned char*)(dst++) = *(unsigned char*)(src++);
  cl_dst = (long*)dst;
  cl_src = (long*)src;
  if (n > 0)
    while(i < n / sizeof(long))
    {
      *cl_dst = *cl_src;
      cl_src++;
      cl_dst++;
      i++;
    }
  return (mem);
}
