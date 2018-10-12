/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 10:24:08 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 10:54:24 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			local_process(char **main_command, int *val, char **env)
{
	char		*str;
	char		**arr;

	str = single_string(main_command);
	arr = ft_strsplit(str, ' ');
	smallprocess(str, env, val, arr);
	free_2d_array((void**)arr);
	exit(-1);
}

void			free_3d_array(void ***array)
{
	int			i;

	i = 0;
	while (array[i])
	{
		free_2d_array((void**)array[i]);
		i++;
	}
	free(array);
}

char			**ft_strarrdup(char **str)
{
	int			i;
	char		**f_str;

	i = -1;
	while (str[++i])
		i++;
	f_str = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (str[++i])
		f_str[i] = ft_strdup(str[i]);
	f_str[i] = NULL;
	return (f_str);
}

char			**ft_strjoinarr(char **str)
{
	int			i;
	char		*ret;
	char		*temp;
	char		**f_ret;

	f_ret = (char **)malloc(sizeof(char *) * 2);
	i = 0;
	ret = ft_strdup(str[i]);
	while (str[++i])
	{
		temp = ft_strdup(str[i]);
		ret = ft_strjoin(ret, " ");
		ret = ft_strjoin(ret, temp);
	}
	f_ret[0] = ft_strdup(ret);
	f_ret[1] = NULL;
	return (f_ret);
}

char			*single_string(char **array)
{
	int			i;
	char		*temp;
	char		*new;

	temp = ft_strnew(1);
	i = 0;
	while (array[i])
	{
		new = ft_strjoin(temp, array[i]);
		free(temp);
		temp = ft_strjoin(new, " ");
		free(new);
		i++;
	}
	return (temp);
}
