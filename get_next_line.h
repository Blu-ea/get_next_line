/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:06:38 by amiguez           #+#    #+#             */
/*   Updated: 2021/12/03 20:04:18 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> //read
# include <stdlib.h> //malloc
# include <stdio.h> //printf

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
int		chek_nl(char *line);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *line, char const *temp);
char	*fr_nl(char *ln);
void	set_nl(char *line, char stat[BUFFER_SIZE + 1]);
#endif
