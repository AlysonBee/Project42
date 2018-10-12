/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 07:29:45 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 13:29:18 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

t_exp				*new_export(char *str)
{
	t_exp			*head;

	head = (t_exp *)malloc(sizeof(t_exp));
	head->envir = ft_strdup(str);
	head->next = NULL;
	return (head);
}

void				free_twice(char **first, char **second)
{
	free_2d_array((void**)first);
	free_2d_array((void**)second);
}

t_exp				*add_export(t_exp **head, char *str)
{
	t_exp			*trav;
	char			**check;
	char			**ano;

	trav = *head;
	while (trav)
	{
		check = ft_strsplit(str, '=');
		ano = ft_strsplit(trav->envir, '=');
		if (ft_strequ(ano[0], check[0]))
		{
			free(trav->envir);
			free_twice(check, ano);
			trav->envir = ft_strdup(str);
			return (trav);
		}
		free_twice(check, ano);
		if (!trav->next)
			break ;
		trav = trav->next;
	}
	trav->next = (t_exp *)malloc(sizeof(t_exp));
	trav->next->envir = ft_strdup(str);
	trav->next->next = NULL;
	return (trav);
}

t_exp				*remove_element(char *name, t_exp **head)
{
	t_exp			*trav;
	t_exp			*temp;

	trav = *head;
	if (head == NULL)
		return (trav);
	while (trav)
	{
		if (trav->next && ft_strcmp(trav->next->envir, name) == 0)
		{
			temp = trav->next;
			if (trav->next->next)
				trav->next = trav->next->next;
			else
				trav->next = NULL;
			free(temp->envir);
			free(temp);
		}
		trav = trav->next;
	}
	return (trav);
}

void				free_export(t_exp *head)
{
	t_exp			*trav;

	while (head)
	{
		trav = head;
		head = head->next;
		free(trav->envir);
		free(trav);
	}
}
