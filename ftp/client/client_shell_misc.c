/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_shell_misc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:18:21 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/02 07:46:17 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			check_command_string(char buffer[],
		char *command)
{
	char	**array;
	char	*str;
	int		i;

	i = 0;
	array = NULL;
	str = ft_strtrim(buffer);
	str = normalize(str);
	if (ft_strchr(str, ' '))
	{
		array = ft_strsplit(str, ' ');
		if (ft_strcmp(command, array[0]) == 0)
		{
			i = 1;
		}
		free_2d_array((void**)array);
	}
	else if (ft_strcmp(str, command) == 0)
		i = 1;
	free(str);
	return (i);
}

char		*normalize(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	return (str);
}

char		wordcount_check(char buffer[])
{
	char	*str;

	str = ft_strtrim(buffer);
	if (ft_wordcount(str) > 0)
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

char		*terminate_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
	return (str);
}
