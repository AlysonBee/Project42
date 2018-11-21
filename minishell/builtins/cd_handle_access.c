/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_handle_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:00:43 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/17 13:56:43 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../minishell.h"
#include <sys/stat.h>

char			*get_word(char **env, char *word)
{
	while (*env)
	{
		if (!ft_strncmp(*env, word, ft_strlen(word)))
			return (*env + ft_strlen(word) + 1);
		env++;
	}
	return (NULL);
}

int				handle_access(char *whereto)
{
	struct stat buff;

	stat(whereto, &buff);
	ft_putstr(whereto);
	if (access(whereto, F_OK) == -1)
		ft_putstr(" : No such directory\n");
	else if (buff.st_mode >= 0100000 && buff.st_mode <= 0100777)
		ft_putstr(" : Not a directory\n");
	else
		ft_putstr(" : Permission denied\n");
	return (-1);
}

char			*strjoin(char *s1, char *s2)
{
	int		size;
	char	*new;

	size = ft_strlen(s1) + ft_strlen(s2);
	new = (char*)malloc(sizeof(char) * size + 1);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	return (new);
}
