/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:08:44 by amiguez           #+#    #+#             */
/*   Updated: 2021/12/03 20:19:22 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*ret;

	i = 0;
	while (src[i])
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	ret[i] = '\0';
	while (i--)
		ret[i] = src[i];
	ret[0] = src[0];
	return (ret);
}

char	*ft_strjoin(char const *line, char const *temp)
{
	char	*s_ret;
	int		i;
	int		j;

	if (!line)
		return (ft_strdup(temp));
	i = -1;
	j = 0;
	s_ret = malloc (sizeof(char) * (ft_strlen(line) + ft_strlen(temp) + 1));
	if (!s_ret)
		return (NULL);
	while (line[++i])
	{
		s_ret[j] = line [i];
		j++;
	}
	i = -1;
	while (temp[++i])
	{
		s_ret[j] = temp[i];
		j++;
	}
	s_ret[j] = '\0';
	return (s_ret);
}

char	*fr_nl(char *ln)
{
	free (ln);
	return (NULL);
}
