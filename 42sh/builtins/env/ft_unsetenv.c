/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:00:24 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 10:12:34 by angonyam         ###   ########.fr       */
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
	char	*temp;

	temp = ft_strtrim(to_check);
	flag = 0;
	left = ft_strsplit(env, '=');
	if (ft_strcmp(temp, left[0]) == 0)
	{
		flag = 1;
		*status = 1;
	}
	free(temp);
	free_2d_array((void**)left);
	return (flag);
}

int			to_equal(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (i);
}

char		**ft_unsetenv(char **env, char *to_unset, int *status)
{
	int		i;
	int		j;
	char	**new;
	int		size;

	new = (char**)ft_memalloc(sizeof(char*) * env_size(env));
	i = -1;
	j = 0;
	while (env[++i])
	{
		size = to_equal(env[i]);
		if (ft_strlen(env[i]) <= 1)
			;
		else if (strncmp(env[i], to_unset, size) == 0)
			*status = 1;
		else
		{
			new[j] = ft_strdup(env[i]);
			j++;
		}
	}
	if (*status != 1)
		ft_printf("Variable not found\n");
	free_2d_array((void**)env);
	return (new);
}
