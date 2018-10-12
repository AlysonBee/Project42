/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:57:12 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/02 20:01:20 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"
#include <unistd.h>
#include <fcntl.h>

void			redirect(char *line)
{
	int		fd;
	int		save;
	pid_t	pid;

	save = dup(1);
	fd = open(line, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, 1);
	printf("hello world\n");
	dup2(1, fd);
	printf("outside\n");
}

int			main(void)
{
	redirect("test.txt");
	return (0);
}
