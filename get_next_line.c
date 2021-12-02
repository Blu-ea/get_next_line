/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:39:20 by amiguez           #+#    #+#             */
/*   Updated: 2021/12/02 21:12:36 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char static	stat[BUFFER_SIZE];
	int			i;

	line = malloc (sizeof(char) * (ft_strlen(stat) + 1));
	if (!line)
		return (0);
	if (1 == fill_line(line, &stat))
		return (line);
	i = read(fd, stat, BUFFER_SIZE);
	if (i <= 0)
		return (fr_nl(line));
	if (i < BUFFER_SIZE)
		return(i_m_buff(&line, &stat));
}

char	*i_m_buff(char **line, char **stat)
{

}

int	fill_line(char *line, char **stat)
{
	int	i;
	int	j;

	while (!*stat[i] && *stat[i] != '\n')
	{
		line[i] = stat[i];
		i++;
	}
	if (*stat[i])
	{
		line[i] = "\n\0";
		while (*stat[i])
		{
			*stat[j] = *stat[i];
			i++;
			j++;
		}
		*stat[i] = 0;
		return (1);
	}
	*stat = 0;
	line[i] = '\0';
	return (0);
}
