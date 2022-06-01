/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:54:07 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/06/01 18:03:33 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET__NEXT__LINE__H
# define __GET__NEXT__LINE__H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> // TO REMOVE

char		*get_next_line(int fd);
static int	ft_newline(char *s, int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *src);
int			ft_strlen(char *str);
char		*ft_strcut(char *src);
#endif
#endif
