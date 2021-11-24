/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:59:28 by amiguez           #+#    #+#             */
/*   Updated: 2021/11/24 22:22:17 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h> //open
#include <stdio.h> //printf

int	main(void)
{
	int		fd;
	char	*str;

	printf("------------\n");
	fd = open("/Users/amiguez/Desktop/get_next_line/test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("1%s\n", str);
	str = get_next_line(fd);
	printf("2%s\n", str);
		str = get_next_line(fd);
	printf("3%s\n", str);
}
