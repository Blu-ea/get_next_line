/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:06:41 by amiguez           #+#    #+#             */
/*   Updated: 2021/11/24 22:25:05 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (!s1 || !s2)
		return (NULL);
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
