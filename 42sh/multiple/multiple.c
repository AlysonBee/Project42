/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:25:19 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 11:17:12 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

t_mult			*new_mult(char *str)
{
	t_mult		*head;

	head = (t_mult *)malloc(sizeof(t_mult));
	head->command = ft_strdup(str);
	head->next = NULL;
	return (head);
}

t_mult			*add_mult(t_mult *head, char *str)
{
	t_mult		*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_mult *)malloc(sizeof(t_mult));
	trav->next->command = ft_strdup(str);
	trav->next->next = NULL;
	return (trav);
}

void			free_mult(t_mult *head)
{
	t_mult		*trav;

	while (head)
	{
		trav = head;
		head = head->next;
		free(trav->command);
		free(trav);
	}
}
