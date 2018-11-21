/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_commands_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 05:24:09 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/18 15:44:02 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

char		**unedited_env(char **environment, char **args)
{
	if (ft_strcmp(args[0], "env") == 0)
	{
		ft_putstr("env: ");
		ft_putstr(args[1]);
		ft_putendl("No such file or directory");
		return (environment);
	}
	else if (ft_strcmp(args[0], "echo") == 0)
	{
		echo(environment, args);
		ft_putchar('\n');
	}
	return (environment);
}

char		**edited_env(char **environment, char **args)
{
	char	**new_array;

	if (ft_strcmp(args[0], "setenv") == 0)
	{
		new_array = ft_setenv(args[1], environment);
		return (new_array);
	}
	else if (ft_strcmp(args[0], "unsetenv") == 0)
	{
		new_array = ft_unsetenv(args[1], environment);
		return (new_array);
	}
	else if (ft_strcmp(args[0], "cd") == 0)
	{
		new_array = ft_cd(args[1], environment);
		return (new_array);
	}
	return (environment);
}
