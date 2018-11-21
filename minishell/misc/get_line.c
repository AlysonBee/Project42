/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 07:39:40 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/17 15:07:26 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../minishell.h"

char		*get_line(int fd)
{
	char	*reading;
	int		size;
	int		i;

	reading = (char*)malloc(sizeof(char) * 1024);
	while ((size = read(fd, reading, 1024)))
	{
		i = 0;
		while (reading[i])
		{
			if (reading[i] == '\n')
			{
				reading[i] = '\0';
				return (reading);
			}
			i++;
		}
	}
	if (size == 0)
	{
		ft_putstr("Interrupted\n");
		exit(1);
	}
	return (NULL);
}
