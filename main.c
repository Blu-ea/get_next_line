/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:59:28 by amiguez           #+#    #+#             */
/*   Updated: 2021/12/03 18:51:15 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h> //open
#include <stdio.h> //printf

int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	i = 5;
	fd = open("/Users/amiguez/Desktop/get_next_line/test.txt", O_RDONLY);
	while (i)
	{
		printf("------debug-------\n");
		str = get_next_line(3);
		printf("------result------\n");
		printf("\n%d = '%s'\n", 6 - i, str);
		free(str);
		i--;
	}
}
