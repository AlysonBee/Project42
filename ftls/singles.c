/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:54:20 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/05 17:52:14 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		single_ls(char *argv, char *options)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!error(argv))
		exit(1);
	while (options[i])
	{
		if (options[i] == 'l' && argv[0] != '.')
		{
			count = 1;
			all(argv);
			ft_printf(" %s ", argv);
		}
		else
		{
			count = 1;
			ft_printf(" %s ", argv);
		}
		i++;
	}
	if (count == 0)
		ft_printf(" %s ", argv);
	ft_printf("\n");
}
