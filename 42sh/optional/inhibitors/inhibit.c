/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inhibit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:10:12 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 13:49:57 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

t_inhibit			*new_inhibit(char *str)
{
	t_inhibit		*new;

	new = (t_inhibit *)malloc(sizeof(t_inhibit));
	new->word = ft_strdup(str);
	new->next = NULL;
	return (new);
}

t_inhibit			*add_inhibit(t_inhibit *head, char *str)
{
	t_inhibit		*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_inhibit*)malloc(sizeof(t_inhibit));
	trav->next->word = ft_strdup(str);
	trav->next->next = NULL;
	return (trav);
}

t_inhibit			*run_inhibit(t_inhibit *head, char *str)
{
	t_inhibit		*trav;

	trav = head;
	if (trav == NULL)
	{
		trav = new_inhibit(str);
		head = trav;
	}
	else
	{
		trav = add_inhibit(head, str);
		trav = head;
	}
	return (trav);
}

void				free_inhibit(t_inhibit *head)
{
	t_inhibit		*trav;

	while (head)
	{
		trav = head;
		head = head->next;
		free(trav->word);
		free(trav);
	}
}
