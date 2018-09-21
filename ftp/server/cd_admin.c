/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_admin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:19:55 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:19:56 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		change_directory(char *line, int sockfd)
{
	handle_cd(line, g_root_path, sockfd);
}

char		*create_path(char *newpath, char *plc)
{
	char	*new;

	new = ft_strjoin(newpath, "/");
	free(newpath);
	newpath = ft_strjoin(new, plc);
	free(new);
	return (newpath);
}

char		*resolve_path(char *path)
{
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	free(path);
	path = ft_strdup(tmp);
	free(tmp);
	return (path);
}

char		**set_current_path(void)
{
	char	buffer[4096];
	char	**ret;

	getcwd(buffer, 4096);
	ret = ft_strsplit(buffer, '/');
	return (ret);
}
