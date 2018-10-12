/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 07:40:26 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 16:54:21 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char			*find_export(t_exp **head, char *target)
{
	char		*ret;
	int			count;
	t_exp		*trav;
	char		**new;

	count = 0;
	trav = *head;
	while (trav)
	{
		new = ft_strsplit(trav->envir, '=');
		if (ft_strcmp(new[0], target) == 0)
		{
			ret = ft_strdup(trav->envir);
			free_2d_array((void**)new);
			return (ret);
		}
		free_2d_array((void**)new);
		trav = trav->next;
		count++;
	}
	return (NULL);
}

char			**export_to_env(char *str, char **env, int *val, t_exp **head)
{
	char		**new;
	char		**ex;
	int			i;

	ex = ft_strsplit(str, ' ');
	i = 0;
	new = (char **)malloc(sizeof(char *) * (ft_arraylen(env) + 3));
	while (env[i])
	{
		new[i] = ft_strdup(env[i]);
		i++;
	}
	new[i] = find_export(head, ex[1]);
	i++;
	new[i] = NULL;
	*val = 1;
	return (new);
}

char			*cleanup(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '^')
			str[i] = ' ';
		i++;
	}
	return (str);
}

int				export_wordcount_check(char *to_export, int *val)
{
	char		**checker;
	int			i;

	checker = ft_strsplit(to_export, ' ');
	i = 0;
	while (checker[i])
		i++;
	if (i >= 3)
	{
		*val = 1;
		ft_printf("export : invalid in this context : %s\n", checker[2]);
		free_2d_array((void**)checker);
		return (-1);
	}
	free_2d_array((void**)checker);
	return (1);
}

char			**export(char *to_export, char **env,
				t_exp **export_table, int *val)
{
	char		**arg;
	char		*to_set;

	if (export_wordcount(to_export) == 0 && ft_strchr(to_export, '='))
	{
		to_export = cleanup(to_export);
		exporting(export_table, to_export);
	}
	else
	{
		if (export_wordcount_check(to_export, val) == -1)
			return (env);
		arg = ft_strsplit(to_export, ' ');
		to_set = find_export(export_table, arg[1]);
		free_2d_array((void**)arg);
		if (to_set == NULL)
		{
			*val = 1;
			return (env);
		}
		env = ft_setenv(env, to_set, val);
		free(to_set);
	}
	*val = 1;
	return (env);
}
