/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:20:00 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:20:02 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "server.h"

char		*newpath_to_root(char *newpath, char *root)
{
	free(newpath);
	newpath = ft_strdup(root);
	return (newpath);
}

char		*backtrack(char *path, char root[])
{
	char		**pathway;
	char		**sp;
	char		*newpath;
	long long	len;
	size_t		i;

	newpath = (char*)malloc(sizeof(char));
	if (!ft_strchr(path, '/'))
		path = resolve_path(path);
	sp = ft_strsplit(path, '/');
	i = 0;
	pathway = set_current_path();
	len = arraylen(pathway) - arraylen(sp);
	if (len < 0)
		return (newpath_to_root(newpath, root));
	while (i < (size_t)len)
	{
		newpath = create_path(newpath, pathway[i]);
		i++;
	}
	if (ft_strstr(newpath, root))
		return (newpath);
	return (newpath_to_root(newpath, root));
}

void		handle_cd(char *line, char root[], int sockfd)
{
	char	**args;
	char	*new;
	char	buffer[4096];
	char	*back;

	new = ft_strjoin(line, " ");
	args = ft_strsplit(new, ' ');
	getcwd(buffer, 4096);
	if (arraylen(args) == 1)
		chdir(root);
	else if (ft_strstr(args[1], ".."))
	{
		back = backtrack(args[1], root);
		chdir(back);
		free(back);
	}
	else if (ft_strcmp(args[1], "/") == 0 || arraylen(args) == 1)
		chdir(root);
	else if (chdir(args[1]) != 0)
	{
		printf("%d : permission denied\n", sockfd);
		send(sockfd, "FAILED", 6, 0);
		return ;
	}
	send(sockfd, "SUCCESS", 7, 0);
}
