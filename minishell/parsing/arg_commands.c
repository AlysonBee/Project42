/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:35:23 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/18 15:44:40 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

char		**multiple_commands(char *line, char **environment, int *flag)
{
	char	**args;
	char	**new_array;

	args = ft_strsplit(line, ' ');
	if (((ft_strcmp(args[0], "cd") == 0))
		|| (ft_strcmp(args[0], "setenv") == 0)
		|| (ft_strcmp(args[0], "unsetenv") == 0))
	{
		new_array = edited_env(environment, args);
		ft_delarray((void**)args);
		return (new_array);
	}
	else if ((ft_strcmp(args[0], "env") == 0)
		|| (ft_strcmp(args[0], "echo") == 0))
	{
		unedited_env(environment, args);
		ft_delarray((void**)args);
		return (environment);
	}
	else
		*flag = 1;
	ft_delarray((void**)args);
	return (environment);
}
