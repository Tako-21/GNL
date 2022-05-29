/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:54:07 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/29 19:01:34 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET__NEXT__LINE__H
# define __GET__NEXT__LINE__H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 11000

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> // TO REMOVE

char		*get_next_line(int fd);
static int	ft_newline(char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *src);
int	ft_strlen(char *str);
char		*ft_strcut(const char *src);
#endif
#endif
