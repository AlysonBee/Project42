/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_arg_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 10:41:59 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 10:42:02 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*first_word(char *str)
{
	char	*new;
	char	**args;

	args = split(str, ' ');
	if (args == NULL)
		return (str);
	new = ft_strdup(str);
	return (new);
}

int			sanity_checker(char *command, int argc)
{
	if (count_args(command) != argc)
		return (-2);
	return (1);
}

int			command_sanity_check(char *command)
{
	char	*arg;

	arg = first_word(command);
	if (arg == NULL)
		return (-1);
	else if (ft_strcmp(arg, "/who") == 0)
		return (sanity_checker(command, 0));
	else if (ft_strcmp(arg, "/msg") == 0)
		return (sanity_checker(command, 2));
	else if (ft_strcmp(arg, "/help") == 0)
		return (sanity_checker(command, 0));
	else
		return (-1);
}
