/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:00:46 by angonyam          #+#    #+#             */
/*   Updated: 2018/10/09 11:00:48 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "lib.h"

char	*push_flags(char *flags, char *arg_line)
{
	int		j;

	j = 1;
	while (arg_line[j])
	{
		if (!isalpha(arg_line[j]))
			exit(1);
		flags = charpush(flags, arg_line[j]);
		j++;
	}
	return (flags);
}

char	*collect_flags(int curr, int argc, char **argv)
{
	int		i;
	char	*flags;

	flags = NULL;
	i = curr;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			flags = push_flags(flags, argv[i]);
		}
		else
			break ;
		i++;
	}
	return (flags);
}
