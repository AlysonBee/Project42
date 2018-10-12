/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewind.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 06:39:40 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/20 13:35:51 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../line.h"
#include <sys/stat.h>
#include "../../shell.h"

int			e_size(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char		**ft_narraydup(char **array)
{
	int		i;
	char	**new;

	new = (char**)malloc(sizeof(char*) * e_size(array) + 2);
	i = 0;
	while (array[i])
	{
		new[i] = ft_strdup(array[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void		print_array(char **array, char *value)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_printf("%s is %s\n", value, array[i]);
		i++;
	}
}

void		cd_error(char *whereto)
{
	struct stat		info;

	if (!lstat(whereto, &info))
		ft_printf("%s : Permission denied\n", whereto);
	else
		ft_printf("%s : No such file or directory\n", whereto);
}

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

char		**going_home(char **env)
{
	char	*pwd;
	char	*old_pwd;
	char	**new;
	int		val;

	val = 1;
	pwd = rewrite(env, "HOME", "PWD");
	old_pwd = rewrite(env, "PWD", "OLDPWD");
	new = ft_setenv(env, pwd, &val);
	free_2d_array((void**)env);
	env = ft_setenv(new, old_pwd, &val);
	free_2d_array((void**)new);
	free(pwd);
	free(old_pwd);
	return (env);
}

char		**reverse(char **env)
{
	char	*pwd;
	char	*old_pwd;
	char	**new;
	int		val;

	val = 1;
	pwd = rewrite(env, "OLDPWD", "PWD");
	old_pwd = rewrite(env, "PWD", "OLDPWD");
	new = ft_setenv(env, pwd, &val);
	free_2d_array((void**)env);
	env = ft_setenv(new, old_pwd, &val);
	free_2d_array((void**)new);
	free(pwd);
	free(old_pwd);
	return (env);
}

char		**regular(char **env)
{
	char	*old_pwd;
	char	*pwd;
	char	cwd[2048];
	char	**new;
	int		val;

	getcwd(cwd, 2048);
	val = 1;
	old_pwd = rewrite(env, "PWD", "OLDPWD");
	pwd = ft_strjoin("PWD=", cwd);
	new = ft_setenv(env, old_pwd, &val);
	free_2d_array((void**)env);
	env = ft_setenv(new, pwd, &val);
	free_2d_array((void**)new);
	free(old_pwd);
	free(pwd);
	return (env);
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

char		**complex_cd(char **env, char *test, int *status)
{
	char	**new_env;
	char	*prev;

	if (ft_strcmp(test, "..") == 10)
	{
		prev = ft_strchr(find_home(env, "OLDPWD"), '=');
		prev++;
		*status = 1;
		chdir(prev);
	}
	else if (chdir(test) != 0)
	{
		cd_error(test);
		*status = -1;
		free(test);
		return (env);
	}
	free(test);
	new_env = regular(env);
	return (new_env);
}

char		**ft_cd(char **env, char *test, int *status)
{
	char	**new_env;
	char	*home;
	char	*whereto;

	whereto = ft_strtrim(test);
	if (!whereto || ft_strcmp(whereto, "~") == 0 ||
			ft_strcmp(whereto, "~/") == 0)
	{
		*status = 1;
		home = ft_strchr(find_home(env, "HOME"), '=');
		home++;
		chdir(home);
		free(whereto);
		return (going_home(env));
	}
	else if (ft_strcmp(whereto, "-") == 0)
	{
		*status = 1;
		home = ft_strchr(find_home(env, "OLDPWD"), '=');
		home++;
		free(whereto);
		return (reverse(env));
	}
	else
		return (complex_cd(env, whereto, status));
}
/*
int			main(int argc, char **argv, char **envp)
{
	char	*rev;
	char	**env;
	char	**new;
	char	**mycd;
	char	*str;
	int		val;
	char	**new_new;
	int		count = 0;

	val = 0;
	new = ft_arraydup(envp);
	while (1)
	{
	//	str = (char*)malloc(sizeof(char) * 1000);
	//	read(0, str, 1000);
		str = ft_read();
		mycd = ft_strsplit(str, ' ');
		if (ft_strstr(str, "exit"))
			exit(1);
		if (mycd[1] == NULL)
			new = ft_cd(new, NULL, &val);
		else 
			new = ft_cd(new, mycd[1], &val);
		int i = 0;
		while (new[i])
		{
			ft_printf(" env is %s\n", new[i]);
			i++;
		 }	
		free_2d_array((void**)mycd);
		ft_printf("status is %d\n", val);
		free(str);
	}
	free_2d_array((void**)new);
	return (0);
}*/
