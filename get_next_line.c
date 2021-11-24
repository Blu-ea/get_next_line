/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:06:40 by amiguez           #+#    #+#             */
/*   Updated: 2021/11/24 22:26:22 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif

void	ft_set_start(char *temp, char *stat_str)
{
	int	i;

	if (!stat_str)
		return ;
	i = 0;
	while (stat_str[i])
	{
		stat_str [i] = temp [i];
		i++;
	}
	temp[ft_strlen(stat_str) + BUFFER_SIZE] = 0;
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
	int			i;
	int			j;
	static char	*stat_str;
	char		*temp;

	j = 0;
	if (!stat_str)
		stat_str = (NULL);
	temp = malloc(sizeof(char) * (ft_strlen(stat_str) + BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	ft_set_start(temp, stat_str);
	stat_str = NULL;
	i = read(fd, &temp[ft_strlen(stat_str)], BUFFER_SIZE);
	if (i == -1)
		return (NULL);
	if (BUFFER_SIZE != i)
		return (ft_free(temp));
	while (j < i)
	{
		if (temp[ft_strlen(stat_str) + j] == '\n')
		{
			stat_str = ft_return(&temp[ft_strlen(stat_str) + j + 1]);
			while (++j != i)
				temp[j] = '\0';
			return (temp);
		}
		j++;
	}
	return (ft_strjoin (temp, get_next_line(fd)));
}