/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 08:56:36 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 13:08:22 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

t_back				*new_back(char *str)
{
	t_back			*new;

	new = (t_back *)malloc(sizeof(t_back));
	new->string = ft_strdup(str);
	new->next = NULL;
	return (new);
}

t_back				*add_back(t_back *head, char *str)
{
	t_back			*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_back *)malloc(sizeof(t_back));
	trav->next->string = ft_strdup(str);
	trav->next->next = NULL;
	return (trav);
}

void				free_back(t_back *head)
{
	t_back			*trav;

	while (head)
	{
		trav = head;
		head = head->next;
		free(trav->string);
		free(trav);
	}
}
