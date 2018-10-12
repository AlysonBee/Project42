/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 09:15:58 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/04 10:55:02 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int						size(char *directory, char *options)
{
	int					size;
	DIR					*dp;
	struct dirent		*dir;
	struct stat			file_stat;
	char				path[PATH_MAX + 1];

	size = 0;
	if (!(dp = opendir(directory)))
		return (size);
	while ((dir = readdir(dp)))
	{
		if (!ft_strchr(options, 'a') && dir->d_name[0] == '.')
			;
		else
		{
			ft_strcpy(path, directory);
			if (directory[ft_strlen(directory) - 1] != '/')
				ft_strcat(path, "/");
			ft_strcat(path, dir->d_name);
			stat(path, &file_stat);
			size += file_stat.st_blocks;
		}
	}
	closedir(dp);
	return (size);
}
