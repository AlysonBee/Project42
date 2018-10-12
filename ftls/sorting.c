/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:53:13 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/04 11:00:37 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			free_files(t_file *head)
{
	t_file		*trav;

	while (head)
	{
		trav = head;
		head = head->next;
		free(trav->info);
		free(trav);
	}
}

int				file_size(t_file *head)
{
	t_file		*trav;
	int			i;

	i = 0;
	trav = head;
	while (trav)
	{
		i++;
		trav = trav->next;
	}
	return (i);
}

t_file			*new_file(char *file)
{
	t_file		*head;

	head = (t_file *)malloc(sizeof(t_file));
	head->info = ft_strdup(file);
	head->next = NULL;
	return (head);
}

t_file			*add_file(t_file *head, char *file)
{
	t_file		*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_file*)malloc(sizeof(t_file));
	trav->next->info = ft_strdup(file);
	trav->next->next = NULL;
	return (trav);
}

char			**array_construct(t_file *head)
{
	char		**new;
	t_file		*trav;
	int			i;

	i = 0;
	trav = head;
	new = (char**)malloc(sizeof(char*) * file_size(head) + 2);
	while (trav)
	{
		new[i] = ft_strdup(trav->info);
		i++;
		trav = trav->next;
	}
	new[i] = NULL;
	free_files(head);
	return (new);
}
