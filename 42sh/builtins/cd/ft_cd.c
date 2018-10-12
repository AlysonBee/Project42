/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewind.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 06:39:40 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:04:56 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/stat.h>
#include "../../shell.h"

char		*rewrite(char **env, char *what_it_was, char *what_it_must_be)
{
	char	*with_an_equal;
	char	*pwd;
	int		i;
	char	**left_right;

	with_an_equal = ft_strjoin(what_it_must_be, "=");
	pwd = NULL;
	i = -1;
	while (env[++i])
	{
		if (ft_strlen(env[i]) == 0)
			continue ;
		left_right = ft_strsplit(env[i], '=');
		if (ft_strcmp(left_right[0], what_it_was) == 0)
		{
			pwd = ft_strjoin(with_an_equal, left_right[1]);
			free_2d_array((void**)left_right);
			break ;
		}
		free_2d_array((void**)left_right);
	}
	free(with_an_equal);
	return (pwd);
}

char		*find_home(char **env, char *target)
{
	int		i;
	char	**checker;

	i = -1;
	while (env[++i])
	{
		if (ft_strlen(env[i]) == 0)
			continue ;
		checker = ft_strsplit(env[i], '=');
		if (ft_strcmp(checker[0], target) == 0)
		{
			free_2d_array((void**)checker);
			return (env[i]);
		}
		free_2d_array((void**)checker);
	}
	return (NULL);
}

char		*root_path(char **env)
{
	char	*root;
	int		i;
	char	**arr;

	i = 0;
	while (env[i])
	{
		arr = ft_strsplit(env[i], '=');
		if (ft_strcmp(arr[0], "HOME") == 0)
		{
			root = ft_strdup(arr[1]);
			free_2d_array((void**)arr);
			return (root);
		}
		free_2d_array((void**)arr);
		i++;
	}
	return (NULL);
}

char		**complex_cd(char **env, char *test, int *status)
{
	char	**new_env;
	char	*prev;
	char	*l;
	char	*go;

	go = NULL;
	if (strncmp(test, "~/", 2) == 0)
	{
		prev = ft_strchr(test, '/');
		if (!(l = root_path(env)))
			return (env);
		go = ft_strjoin(l, prev);
		free(l);
		chdir(go);
	}
	else if (chdir(test) != 0)
	{
		cd_error(test, status);
		return (env);
	}
	*status = 1;
	free(test);
	go != NULL ? free(go) : 0;
	new_env = regular(env);
	return (new_env);
}

char		**ft_cd(char **env, char *test, int *status)
{
	char	*home;
	char	*whereto;

	whereto = test == NULL ? NULL : ft_strtrim(test);
	if (!whereto || ft_strcmp(whereto, "~") == 0 ||
			ft_strcmp(whereto, "~/") == 0)
	{
		home = ft_strchr(find_home(env, "HOME"), '=');
		home++;
		chdir(home);
		free(whereto);
		return (going_home(env, status));
	}
	else if (ft_strcmp(whereto, "-") == 0)
	{
		home = ft_strchr(find_home(env, "OLDPWD"), '=');
		home++;
		ft_printf("%s\n", home);
		chdir(home);
		free(whereto);
		return (reverse(env, status));
	}
	else
		return (complex_cd(env, whereto, status));
}
