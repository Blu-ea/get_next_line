/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:39:20 by amiguez           #+#    #+#             */
/*   Updated: 2021/12/07 15:24:53 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (i <= 0)
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
