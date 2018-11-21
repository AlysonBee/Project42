/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 09:20:55 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/18 15:45:13 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		put_error(char *message)
{
	ft_putendl(message);
	return (-1);
}

static int		single_command(char *line, char **environment)
{
	if (ft_strcmp(line, "env") == 0)
	{
		ft_env(environment);
		return (1);
	}
	else if (ft_strcmp(line, "echo") == 0)
	{
		ft_putchar('\n');
		return (1);
	}
	else if (ft_strcmp(line, "setenv") == 0)
		return (put_error("Usage: setenv <variable>=<to set>"));
	else if (ft_strcmp(line, "unsetenv") == 0)
		return (put_error("Usage: unsetenv <variable>=<to unset>"));
	else
		return (0);
}

char			**how_many_commands(char *str, char **environment, int *flag)
{
	char		**new_array;

	if (single_command(str, environment) == 0)
	{
		if (ft_strncmp(str, "cd", 2) == 0)
		{
			new_array = ft_cd(NULL, environment);
			return (new_array);
		}
		else
			*flag = 1;
	}
	return (environment);
}
