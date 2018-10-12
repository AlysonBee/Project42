/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:32:58 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/19 11:57:45 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

int			env_size(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char		*a_string(char *left, char *right, int *val)
{
	char	*temp;
	char	*new;

	*val = 1;
	temp = ft_strjoin(left, "=");
	new = ft_strjoin(temp, right);
	free(temp);
	return (new);
}

char		**ft_setenv(char **envp, char *to_set, int *status)
{
	int		i;
	char	**new;
	char	**src;
	char	**dst;

	src = ft_strsplit(to_set, '=');
	new = (char**)ft_memalloc(sizeof(char*) * env_size(envp) + 2);
	i = -1;
	while (envp[++i])
	{
		if (ft_strlen(envp[i]) == 0)
			continue ;
		dst = ft_strsplit(envp[i], '=');
		if (ft_strcmp(dst[0], src[0]) == 0)
			new[i] = a_string(dst[0], src[1], status);
		else
			new[i] = ft_strdup(envp[i]);
		free_2d_array((void**)dst);
	}
	if (*status != 1)
		new[++i] = a_string(src[0], src[1], status);
	new[i] = NULL;
	free_2d_array((void**)src);
	return (new);
}
/*
int		main(int argc, char **argv, char **envp)
{
	char	**temp;
	int		st;
	char	**new;

	st = 0;
	temp = ft_arraydup(envp);
	new = ft_setenv(temp, "sad=AOSFAS", &st);
	int i = 0;
	while (new[i])
	{
		ft_printf("new is %s\n", new[i]);
		i++;
	}
	ft_printf("st is %d\n", st);
} */
