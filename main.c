/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:59:28 by amiguez           #+#    #+#             */
/*   Updated: 2021/12/01 11:03:57 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h> //open
#include <stdio.h> //printf

int	main(void)
{
	int		fd;
	char	*str;

	printf("------debug------\n");
	fd = open("/Users/amiguez/Desktop/get_next_line/test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("------result------\n");
	printf("1 = '%s'\n", str);
}
