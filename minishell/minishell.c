/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:09:09 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/17 15:11:30 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "minishell.h"

char			*setup(int *flag)
{
	char	*input;
	char	*new;

	new = NULL;
	quit_handler();
	ft_putstr("$>");
	*flag = 0;
	input = get_line(0);
	new = tabspace(input);
	free(input);
	return (new);
}

void			minishell(char **envi)
{
	char	*input;
	char	**temp_env;
	int		flag;
	int		i;

	while (42)
	{
		input = setup(&flag);
		i = wordcount(input);
		if (ft_strlen(input) == 1 || (input[0] == '\n' || ft_isspace(input[0])))
			;
		else
		{
			if ((ft_strncmp(input, "exit", 4) == 0))
				ft_exit(input, envi);
			else if (i == 0)
				temp_env = ft_arraydup(how_many_commands(input, envi, &flag));
			else if (i >= 1)
				temp_env = ft_arraydup(multiple_commands(input, envi, &flag));
			if (flag == 1)
				process(input, temp_env);
			envi = ft_arraydup(temp_env);
		}
		free(input);
	}
}

static char		*update_shell_lv(char *environment)
{
	char		*lv;
	char		*new_lv;
	int			temp_n;

	lv = ft_strchr(environment, '=');
	lv++;
	temp_n = ft_atoi(lv);
	temp_n++;
	lv = ft_itoa(temp_n);
	new_lv = ft_strjoin("SHLVL=", lv);
	free(lv);
	return (new_lv);
}

char			*one_level_deep(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("SHLVL=", envp[i], 6) == 0)
			return (update_shell_lv(envp[i]));
		i++;
	}
	return (NULL);
}

int				main(int argc, char **argv, char **envp)
{
	int		size;
	char	**environment;
	char	*shlvl;
	int		i;

	argc = 0;
	argv = NULL;
	size = ft_2d_array_len(envp);
	shlvl = one_level_deep(envp);
	environment = (char**)malloc(sizeof(char*) * size + 1);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("SHLVL=", envp[i], 6) == 0)
		{
			environment[i] = ft_strdup(shlvl);
			free(shlvl);
		}
		else
			environment[i] = ft_strdup(envp[i]);
		i++;
	}
	environment[i] = NULL;
	minishell(environment);
	return (0);
}
