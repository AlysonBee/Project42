/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:00:24 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/19 11:58:54 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

int			env_size(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

int			checker(char *env, char *to_check, int *status)
{
	char	**left;
	int		flag;

	flag = 0;
	left = ft_strsplit(env, '=');
	if (ft_strcmp(to_check, left[0]) == 0)
	{
		flag = 1;
		*status = 1;
	}
	free_2d_array((void**)left);
	return (flag);
}

char		**ft_unsetenv(char **env, char *again, int *status)
{
	int		i;
	int		j;
	char	**new;
	char	**ft;
	char	*to_unset;

	to_unset = ft_strtrim(again);
	new = (char**)ft_memalloc(sizeof(char*) * env_size(env));
	i = -1;
	j = 0;
	while (env[++i])
	{
		if (ft_strlen(env[i]) == 0)
			continue ;
		if (checker(env[i], to_unset, status) == 1)
			continue ;
		new[j] = ft_strdup(env[i]);
		j++;
	}
	new[j] = NULL;
	if (*status != 1)
		ft_printf("Variable not found\n");
	free(to_unset);
	free_2d_array((void**)env);
	return (new);
}

int			main(int argc, char **argv, char **envp)
{
	int		i;
	char	**new;
	int		val;
	char	*str;
	char	**args;

	new = ft_arraydup(envp);
	while (42)
	{
		val = 0;
		str = (char*)malloc(sizeof(char) * 1000);
		read(0, str, 1000);
		if (ft_strstr(str, "exit"))
			break ;
		args = ft_strsplit(str, ' ');
		new = ft_unsetenv(new, args[1], &val);
		int j = 0;
		while (new[j])
		{
			ft_printf("env is %s\n", new[j]);
			j++;
		}
		free_2d_array((void**)args);
		free(str);
		ft_printf("val is %d\n", val);
	}
	free_2d_array((void**)new);
	free(str);
	return (0);
}
