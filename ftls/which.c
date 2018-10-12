/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:14:12 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/04 16:37:19 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			which(char **argv, int *i, char *commands, int argc)
{
	int		j;
	int		flag;

	(void)argc;
	flag = 0;
	j = *i;
	if (!error(argv[j]))
		flag = 1;
	else if (argv[j][0] != '-' && argv[j + 1] &&
			argv[j + 1][0] != '-')
	{
		flag = 1;
		*i += multiples(argv, j, commands, argc);
	}
	else
	{
		flag = ft_ls(argv[j], commands);
		if (flag == -1)
			single_ls(argv[j], commands);
	}
	return (flag);
}
