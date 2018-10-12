/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:32:58 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:06:05 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char		*empty_setenv(char **src, char **envp)
{
	free_2d_array((void**)src);
	free_2d_array((void**)envp);
	return (NULL);
}

char		*append_env(char *target, int *status)
{
	char	*ret;

	ret = ft_strdup(target);
	free(target);
	*status = 1;
	return (ret);
}

char		**ft_setenv(char **envp, char *line, int *status)
{
	int		i;
	char	**new;
	char	**src;
	char	**dst;
	char	*to_set;

	to_set = ft_strtrim(line);
	if (!(src = setenv_intro(line, status)))
		return (envp);
	new = (char**)ft_memalloc(sizeof(char*) * (ev_size(envp) + 4));
	i = 0;
	while (envp[i])
	{
		dst = ft_strsplit(envp[i], '=');
		if (ft_strcmp(dst[0], src[0]) == 0)
			new[i] = a_string(dst[0], src[1], status);
		else
			new[i] = ft_strdup(envp[i]);
		i++;
		free_2d_array((void**)dst);
	}
	if (*status != 1)
		new[i++] = append_env(to_set, status);
	new[i] = empty_setenv(src, envp);
	return (new);
}
