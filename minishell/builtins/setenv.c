/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:02:31 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/16 01:26:50 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "../minishell.h"
#define MALLOCING (char*)malloc(sizeof(char)*(size+(ft_strlen(descrip)-size)+1))

static int			name_size(char *new_line)
{
	int i;

	i = 0;
	while (new_line[i] != '=' && new_line[i])
		i++;
	i++;
	return (i);
}

static char			*rewrite_variable(char *array, char *descrip,
		int env_name_size)
{
	int		size;
	char	*new_name;
	int		i;

	size = env_name_size;
	while (array[size])
		size++;
	new_name = (char*)malloc(sizeof(char) * 1000);
	i = 0;
	while (descrip[i])
	{
		new_name[i] = descrip[i];
		i++;
	}
	new_name[i] = '\0';
	return (new_name);
}

static char			**construct(char **new_array, char *new_item,
		int env_name_size, char **array)
{
	int		flag;
	int		i;
	int		temp_size;

	flag = 0;
	i = 0;
	while (array[i])
	{
		temp_size = 0;
		while (array[i][temp_size] != '=')
			temp_size++;
		if (strncmp(array[i], new_item, temp_size) == 0)
		{
			new_array[i] = rewrite_variable(array[i], new_item, env_name_size);
			flag = 1;
		}
		else
			new_array[i] = ft_strdup(array[i]);
		i++;
	}
	if (flag == 0)
		new_array[i++] = ft_strdup(new_item);
	new_array[i] = NULL;
	return (new_array);
}

static char			**append_to_array(char **array, char *new_item)
{
	char	**new_array;
	int		size;
	int		env_name_size;

	size = 0;
	while (array[size])
		size++;
	env_name_size = name_size(new_item);
	new_array = (char**)malloc(sizeof(char*) * (size * 2));
	return (construct(new_array, new_item, env_name_size, array));
}

char				**ft_setenv(char *to_set, char **environment)
{
	int		i;
	char	**new_environ;
	int		size;

	i = 0;
	if (!strchr(to_set, '=') || !to_set)
	{
		ft_putstr("Usage: setenv <variable namte>=<vaule>\n");
		return (environment);
	}
	size = 0;
	while (to_set[size] != '=')
		size++;
	i = 0;
	new_environ = append_to_array(environment, to_set);
	ft_delarray((void**)environment);
	return (new_environ);
}
