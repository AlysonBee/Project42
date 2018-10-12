/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordjoin2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:33:32 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 13:48:11 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char			*join_commands(t_inhibit *head)
{
	t_inhibit	*trav;
	char		*temp;
	char		*file;

	file = (char*)ft_memalloc(sizeof(char));
	trav = head;
	while (trav)
	{
		if (ft_strlen(trav->word) <= 0)
		{
			trav = trav->next;
			continue ;
		}
		temp = ft_strjoin(file, trav->word);
		file = ft_strjoin(temp, "\n");
		free(temp);
		temp = ft_strdup(file);
		free(file);
		trav = trav->next;
	}
	free_inhibit(head);
	return (temp);
}
