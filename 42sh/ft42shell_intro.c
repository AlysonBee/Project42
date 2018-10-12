/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42shell_intro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:20:26 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:13:15 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char				*shlvl(char *value)
{
	char			*temp;
	int				num;
	char			*l;

	num = ft_atoi(value);
	num++;
	temp = ft_itoa(num);
	l = ft_strjoin("SHLVL=", temp);
	free(temp);
	return (l);
}

char				*shellname(char *value)
{
	char			name[2048];
	char			*shell;
	char			*temp;
	char			*val;

	val = ft_strjoin(value, "=");
	getcwd(name, 2048);
	shell = ft_strjoin(name, "/42sh");
	temp = ft_strjoin(shell, " ");
	free(shell);
	shell = ft_strjoin(val, temp);
	free(temp);
	free(val);
	return (shell);
}

int					main(void)
{
	char			**env;
	int				i;
	char			**arg;
	t_exp			*head;
	extern char		**environ;

	env = (char **)malloc(sizeof(char *) * (ft_arraylen(environ) + 2));
	i = 0;
	while (environ[i])
	{
		arg = ft_strsplit(environ[i], '=');
		if (ft_strcmp(arg[0], "SHELL") == 0)
			env[i] = shellname(arg[0]);
		else if (ft_strcmp(arg[0], "SHLVL") == 0)
			env[i] = shlvl(arg[1]);
		else
			env[i] = ft_strdup(environ[i]);
		i++;
		free_2d_array((void**)arg);
	}
	env[i] = NULL;
	head = NULL;
	ft_42sh(env, head);
	return (0);
}
