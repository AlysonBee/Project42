/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 06:51:48 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/05 10:14:23 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					permissions(char *file)
{
	struct stat			filetype;

	lstat(file, &filetype);
	ft_printf((S_ISDIR(filetype.st_mode)) ? "d" : "-");
	ft_printf((filetype.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((filetype.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((filetype.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((filetype.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((filetype.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((filetype.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((filetype.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((filetype.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((filetype.st_mode & S_IXOTH) ? "x" : "-");
	ft_printf(" %d ", (int)(filetype.st_nlink));
}

void					user_info_and_file_size(char *file)
{
	struct stat			filetype;
	struct passwd		*user;
	struct group		*gr;

	lstat(file, &filetype);
	user = getpwuid(filetype.st_uid);
	if (!user)
		return ;
	ft_printf(" %s ", user->pw_name);
	gr = getgrgid(filetype.st_gid);
	if (!gr)
		return ;
	ft_printf("%s ", gr->gr_name);
	ft_printf(" %d ", (int)filetype.st_size);
}

void					last_created_modified_and_file_name(char *file)
{
	struct stat			filetype;
	char				*timing;
	int					i;

	lstat(file, &filetype);
	timing = ctime(&filetype.st_mtime);
	if (!timing)
		return ;
	i = 3;
	while (i < 16)
	{
		ft_printf("%c", timing[i]);
		i++;
	}
}

void					all(char *file)
{
	if (file == NULL)
		;
	else
	{
		permissions(file);
		user_info_and_file_size(file);
		last_created_modified_and_file_name(file);
	}
}

void					print_type(char *target, char *file, char *options)
{
	char				*temp;
	char				*t2;

	temp = ft_strjoin(target, "/");
	t2 = ft_strjoin(temp, file);
	free(temp);
	if (ft_strchr(options, 'l'))
	{
		all(t2);
		ft_printf(" %s\n", file);
	}
	else
	{
		ft_printf("%s\n", file);
	}
}
