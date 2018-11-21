/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:02:21 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/18 12:45:49 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../minishell.h"
#include "../libft/libft.h"
#include <stdlib.h>

static char		**unset_environment(char **environment, int position)
{
	char	**new_array;
	int		size;
	int		i;
	int		j;

	size = 1000;
	while (environment[size])
		size++;
	new_array = (char**)malloc(sizeof(char*) * (size * 2));
	i = 0;
	j = 0;
	while (environment[i])
	{
		if (i == position)
			i++;
		else
		{
			new_array[j] = ft_strdup(environment[i]);
			j++;
			i++;
		}
	}
	new_array[j] = NULL;
	ft_delarray((void**)environment);
	return (new_array);
}

char			**ft_unsetenv(char *to_unset, char **environment)
{
	int		i;
	int		position;
	int		size;

	i = 0;
	while (environment[i])
	{
		size = 0;
		while (environment[i][size] != '=')
			size++;
		if (strncmp(environment[i], to_unset, size) == 0)
		{
			position = i;
			break ;
		}
		i++;
	}
	if (environment[i] == NULL)
	{
		ft_putendl("Variable not found\n");
		return (environment);
	}
	return (unset_environment(environment, position));
}
