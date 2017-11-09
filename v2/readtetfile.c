/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtetfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:14:44 by aho               #+#    #+#             */
/*   Updated: 2017/11/07 00:04:36 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUF_SIZE 20

int readtetfile(char *argv, t_list **list)
{
    int fd;
    int ret;
    char buf[BUF_SIZE];
    int alpha;

    alpha = 65;
    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("open() failed \n");
        return (1);
    }

    while ((ret = read(fd, buf, BUF_SIZE)))
//  while ((ret = read(fd, buf, BUF_SIZE)) > 21)
//  while ((ret = read(fd, buf + bufdone, BUF_SIZE - bufdone)) > 21)
    {
        buf[ret] = '\0';
//      check_buf(buf);
        if (isvalidpiece(buf) == 1)
        {
            ft_lstappend(list, ft_lstnew(buf, 21, alpha));
            alpha++;
        }
        ret = read(fd, buf, 1);
    }

//  while ((ret = read(fd, buf, BUF_SIZE)) > 20)
//  {
//      buf[ret] = '\n';
//      buf[ret + 1] = '\0';
//      if (isvalidpiece(buf) == 1)
//      {
//          ft_lstappend(&linked_list, ft_lstnew(buf, 21, alpha));
//          alpha++;
//      }
//  }

    ft_putstr("\n    hurray! file successfully opened - fd: ");
    ft_putnbr(fd);
    ft_putchar('\n');

    if (close(fd) == -1)
    {
        ft_putstr("close() failed \n");
        return (1);
    }
	return (0);
}
