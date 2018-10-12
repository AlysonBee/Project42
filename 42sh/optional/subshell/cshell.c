/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cshell.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:32:07 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/15 08:04:07 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

t_subshell			*new_command(char *line)
{
	t_subshell		*new;

	new = (t_subshell *)malloc(sizeof(t_subshell));
	new->command = ft_strdup(line);
	new->next = NULL;
	return (new);
}

t_subshell			*add_command(t_subshell *head, char *line)
{
	t_subshell 		*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_subshell*)malloc(sizeof(t_subshell));
	trav->next->command = ft_strdup(line);
	trav->next->next = NULL;
	return (trav);
}

void				free_commands(t_subshell *head)
{
	t_subshell		*trav;

	while (head)
	{
		trav = head;
		head = head->next;
		free(trav->command);
		free(trav);
	}
}



















