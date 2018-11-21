/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 05:14:20 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/15 05:20:42 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

int				quotation_check(char **echoing, char quote)
{
	int			i;
	int			j;
	int			comma_count;

	comma_count = 0;
	i = 1;
	while (echoing[i])
	{
		j = 0;
		while (echoing[i][j])
		{
			if (echoing[i][j] == quote)
				comma_count++;
			j++;
		}
		i++;
	}
	if (comma_count % 2 != 0)
		return (-1);
	return (comma_count);
}

char			which_comma(char **echoing)
{
	int			i;
	int			j;
	char		c;

	c = 0;
	i = -1;
	while (echoing[++i])
	{
		j = -1;
		while (echoing[i][++j])
		{
			if (echoing[i][j] == '\'')
				c = '\'';
			else if (echoing[i][j] == '\"')
				c = '\"';
			if (c == '\'' || c == '\"')
				break ;
		}
		if (c == '\"' || c == '\'')
			break ;
	}
	if (quotation_check(echoing, c) == -1)
		write(1, "\n", 1);
	return (c);
}
