/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh-4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 07:07:26 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 07:18:04 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*whitespace_trim(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	return (str);
}

char		**andor_management(char *str, char **env, int *val)
{
	int		count;
	t_andor	*head;

	*val = 1;
	count = logical_op_count(str);
	head = chaining(str, count);
	env = command_list(head, env);
	return (env);
}

char		*n_trim(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
	return (str);
}

char		*remove_dquotes(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			str[i] = ' ';
		i++;
	}
	return (str);
}
