/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh-1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 06:48:19 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 16:43:28 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_arraylen(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char		**ft_arraydup(char **array)
{
	int		i;
	char	**new;

	new = (char**)malloc(sizeof(char*) * ft_arraylen(array) + 1);
	i = 0;
	while (array[i])
	{
		new[i] = ft_strdup(array[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void		free_2d_array(void **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int			wordcount(char *str)
{
	int		i;
	char	**new;

	new = ft_strsplit(str, ' ');
	if (str == NULL)
		return (0);
	i = 0;
	while (new[i])
		i++;
	free_2d_array((void**)new);
	return (i);
}

char		*ag_function(char *comm)
{
	char	*ag;
	int		i;

	ag = (char*)malloc(sizeof(char) * ft_strlen(comm));
	i = 0;
	while (comm[i] && comm[i] != '\n' && comm[i] != ' ')
	{
		ag[i] = comm[i];
		i++;
	}
	ag[i] = '\0';
	free(comm);
	comm = ft_strdup(ag);
	free(ag);
	return (comm);
}
