/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:59:29 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/17 11:25:52 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

t_echosub		*new_echo(char *words)
{
	t_echosub	*new;

	new = (t_echosub *)malloc(sizeof(t_echosub));
	new->str = ft_strdup(words);
	new->next = NULL;
	return (new);
}

t_echosub		*add_echo(t_echosub *head, char *words)
{
	t_echosub	*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_echosub*)malloc(sizeof(t_echosub));
	trav->next->str = ft_strdup(words);
	trav->next->next = NULL;
	return (trav);
}

void			print_echo(t_echosub *head)
{
	t_echosub	*trav;

	trav = head;
	while (trav)
	{
		ft_printf("echosub> %s", trav->str);
		trav = trav->next;
	}
}

void			free_echo(t_echosub *head)
{
	t_echosub	*trav;

	while (head)
	{
		trav = head;
		head = head->next;
		free(trav->str);
		free(trav);
	}
}
 
