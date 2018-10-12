/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:59:08 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/02 14:31:07 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_rec			*new_rec(char *str)
{
	t_rec		*new;

	new = (t_rec*)malloc(sizeof(t_rec));
	new->path = ft_strdup(str);
	new->next = NULL;
	return (new);
}

t_rec			*add_rec(t_rec *head, char *str)
{
	t_rec		*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_rec*)malloc(sizeof(t_rec));
	trav->next->path = ft_strdup(str);
	trav->next->next = NULL;
	return (trav);
}

void			print_recurse(t_rec *head)
{
	t_rec		*trav;

	trav = head;
	while (trav)
	{
		ft_printf("trav is %s\n", trav->path);
		trav = trav->next;
	}
}

void			free_recurse(t_rec *head)
{
	t_rec		*trav;

	while (head)
	{
		trav = head;
		head = head->next;
		free(trav->path);
		free(trav);
	}
}
