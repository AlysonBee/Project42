/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:15:18 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 16:58:41 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char		*k_size(char *lines)
{
	int		k;
	int		flag;
	char	*file;
	int		j;

	file = NULL;
	flag = 0;
	k = 0;
	j = -1;
	while (lines[++j])
		if (lines[j] == '$')
		{
			j++;
			if (lines[j] == '{')
			{
				j++;
				k = export_substr(&lines[j]);
				flag = 1;
				break ;
			}
		}
	if (flag == 1)
		file = ft_strsub(lines, j, k);
	return (file);
}

char		*export_to_print(char *str, t_exp **head)
{
	int		i;
	char	**lines;
	char	*file;

	i = 0;
	lines = ft_strsplit(str, ' ');
	while (lines[i])
	{
		file = k_size(lines[i]);
		if (file)
			break ;
		i++;
	}
	if (!file)
	{
		free(str);
		return (NULL);
	}
	return (export_rewrite(file, lines, i, head));
}

void		erase_node(int count, t_exp **head)
{
	t_exp	*trav;
	int		i;

	trav = *head;
	i = 0;
	while (trav)
	{
		if (i == count)
		{
			trav = trav->next;
			trav->next = trav->next->next;
			free(trav->envir);
			free(trav);
			return ;
		}
		trav = trav->next;
	}
}
