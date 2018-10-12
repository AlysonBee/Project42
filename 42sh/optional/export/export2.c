/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:11:30 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 16:54:38 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

int				export_substr(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '}')
			return (i);
		i++;
	}
	return (0);
}

char			*export_rewrite(char *var, char **lines, int i, t_exp **head)
{
	char		*file;
	t_exp		*trav;
	char		**arr;

	file = NULL;
	trav = *head;
	while (trav)
	{
		arr = ft_strsplit(trav->envir, '=');
		if (ft_strcmp(arr[0], var) == 0)
		{
			file = ft_strdup(arr[1]);
			free_2d_array((void**)arr);
			return (export_create_line(file, lines, i));
		}
		free_2d_array((void**)arr);
		trav = trav->next;
	}
	return (export_create_line(file, lines, i));
}

int				export_wordcount(char *str)
{
	int			i;
	char		*to_count;
	int			count;

	i = 0;
	count = 0;
	to_count = ft_strtrim(str);
	while (to_count[i])
	{
		if (to_count[i] == ' ')
			count++;
		i++;
	}
	free(to_count);
	return (count);
}

t_exp			*exporting(t_exp **head, char *str)
{
	t_exp		*trav;

	trav = *head;
	if (trav == NULL)
	{
		trav = new_export(str);
		*head = trav;
	}
	else
	{
		trav = add_export(head, str);
		trav = *head;
	}
	return (trav);
}

char			*export_create_line(char *file, char **line, int i)
{
	char		*new;
	char		*temp;
	int			j;

	temp = ft_strnew(1);
	j = 0;
	while (line[j])
	{
		if (file == NULL && j == i)
		{
			j++;
			continue ;
		}
		if (j == i)
			new = ft_strjoin(temp, file);
		else
			new = ft_strjoin(temp, line[j]);
		free(temp);
		temp = ft_strjoin(new, " ");
		free(new);
		j++;
	}
	free_2d_array((void**)line);
	return (temp);
}
