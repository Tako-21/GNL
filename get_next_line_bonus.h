/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:54:07 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/06/06 14:05:34 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET__NEXT__LINE__H
# define __GET__NEXT__LINE__H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# ifndef CALL
# define CALL 1
# endif

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdint.h>

char		*get_next_line(int fd);
int			ft_newline(char *s);
char		*ft_strjoin(char *line, char *buffer);
char		*ft_strdup(const char *src);
int			ft_strlen(char *str);
char		*ft_strcut(char *src);
int			ft_strchr(const char *string, int searchedChar );
void		*ft_memmove(void *dest, const void *src, size_t n);
char		*ft_parsebuff(char *buffer);
#endif
