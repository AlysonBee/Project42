/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:52:22 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/17 02:19:38 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../minishell.h"

static char		*old_dir(char **environment)
{
	int			i;
	char		*old_pwd;
	char		*str;

	old_pwd = NULL;
	str = NULL;
	i = 0;
	while (42)
	{
		if (ft_strncmp(environment[i], "PWD=", 4) == 0)
		{
			str = strchr(environment[i], '=');
			str++;
			break ;
		}
		i++;
	}
	if (str)
		old_pwd = strjoin("OLDPWD=", str);
	return (old_pwd);
}

static int		navigate_home(char **environment)
{
	int			i;
	int			test;
	char		*env_location;

	test = 0;
	i = 0;
	while (environment[i])
	{
		if (strncmp(environment[i], "HOME=", 5) == 0)
		{
			env_location = strchr(environment[i], '=');
			env_location++;
			test = chdir(env_location);
			return (1);
		}
		i++;
	}
	return (-1);
}

static char		*new_working_d(char new_working_dir[])
{
	char		*new;

	getcwd(new_working_dir, 1024);
	new = ft_strjoin("PWD=", new_working_dir);
	return (new);
}

static int		ft_processing(char *whereto, char **environment)
{
	char		*str;

	if (!whereto || (ft_strlen(whereto) == 1 && whereto[0] == '~'))
	{
		if (navigate_home(environment) == 1)
			return (1);
	}
	else if (ft_strncmp(whereto, "~/", 2) == 0 ||
			ft_strncmp(whereto, "/", 1) == 0)
	{
		str = ft_strchr(whereto, '/');
		++str;
		if (!chdir(get_word(environment, "HOME")))
		{
			if (chdir(str) != 0)
				return (handle_access(str));
		}
		else
			return (1);
	}
	else if (!ft_strcmp(whereto, "-"))
		chdir(get_word(environment, "OLDPWD"));
	else
		return (chdir(whereto) != 0 ? handle_access(whereto) : 1);
	return (-1);
}

char			**ft_cd(char *whereto, char **environment)
{
	char		*env_location;
	char		new_working_dir[1024];
	char		*old_working_dir;
	char		**new_array;

	if (ft_processing(whereto, environment) == 1)
	{
		old_working_dir = old_dir(environment);
		env_location = new_working_d(new_working_dir);
		new_array = ft_setenv(env_location, environment);
		free(env_location);
		environment = ft_setenv(old_working_dir, new_array);
		free(old_working_dir);
	}
	return (environment);
}
