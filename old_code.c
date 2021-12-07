/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:38:58 by amiguez           #+#    #+#             */
/*   Updated: 2021/12/07 15:20:49 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
											Code numéros 1
*/

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s_ret;
	int		i;
	int		j;
	char	*temp;

	if (!s1)
		return (s2);
	i = -1;
	j = 0;
	s_ret = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s_ret)
		return (NULL);
	while (s1[++i])
		s_ret[j++] = s1 [i];
	i = -1;
	while (s2[++i])
		s_ret[j++] = s2[i];
	s_ret[j] = '\0';
	temp = s_ret;
	free (s_ret);
	return (temp);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*ret;
	char	*temp;

	i = 0;
	while (src[i])
		i++;
	ret = malloc(sizeof(char) * i + 1);
	if (!ret)
		return (NULL);
	ret[i] = '\0';
	while (i--)
		ret[i] = src[i];
	ret[0] = src[0];
	temp = ret;
	free (ret);
	return (temp);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long int	i;
	char				*str_ret;

	i = 0;
	str_ret = malloc (count * size);
	if (!str_ret)
		return (NULL);
	while (i < count * size)
	{
		str_ret[i] = 0;
		i++;
	}
	return (str_ret);
}

#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif

int	ft_set_start(char *temp, char *stat_str)
{
	int	i;

	if (!stat_str)
		return (0);
	i = 0;
	while (stat_str[i])
	{
		stat_str [i] = temp [i];
		i++;
	}
	temp[ft_strlen(stat_str) + BUFFER_SIZE] = 0;
	return (i);
}

char	*ft_free(char *str_ret)
{
	char	*ret;

	ret = str_ret;
	free (str_ret);
	return (ret);
}

char	*ft_return(char *temp)
{
	char	*str;
	int		i;
	char	*ret;

	i = ft_strlen(temp);
	str = malloc (sizeof(char) * (i + 1));
	i = 0;
	while (temp[i])
	{
		str[i] = temp [i];
		i++;
	}
	ret = str;
	free (str);
	return (ret);
}

char	*get_next_line(int fd)
{
	int			y;
	int			i;
	static char	*stat_str;
	char		*line;

	i = 0;
	if (!stat_str)
		stat_str = (NULL);
	line = ft_calloc((ft_strlen(stat_str) + BUFFER_SIZE + 1), sizeof (char));
	if (!line)
		return (NULL);
	y = ft_set_start(line, stat_str);
	free(stat_str);
	stat_str = 0;
	while (1)
	{
		i = read(fd, &line[y], BUFFER_SIZE);
		while 
	}
	return (NULL);
}

/*
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> //read
# include <stdlib.h> //malloc

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
char	*ft_return(char *temp);
char	*ft_free(char *str_ret);
int		ft_set_start(char *temp, char *stat_str);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t count, size_t size);

#endif
*/

/*


===============================

	CE CODE FONCTION BIEN !!

===============================

*/



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:39:20 by amiguez           #+#    #+#             */
/*   Updated: 2021/12/07 15:18:13 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char static	stat[BUFFER_SIZE + 1];
	char		temp[BUFFER_SIZE + 1];
	int			i;

	line = 0;
	i = 1;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (*stat)
	{
		line = ft_strdup(stat);
		*stat = 0;
	}
	while (chek_nl(line) == -1 && i != 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0)
			return (fr_nl(line));
		temp[i] = '\0';
		line = ft_strjoin(line, temp);
	}
	if (chek_nl(line) != -1)
		set_nl(line, (char *)stat);
	return (line);
}

int	chek_nl(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	set_nl(char *line, char *stat)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strdup(&line[chek_nl(line) + 1]);
	line[chek_nl(line) + 1] = '\0';
	while (temp[i])
	{
		stat[i] = temp[i];
		i++;
	}
	stat[i] = 0;
	free (temp);
}
