/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 06:32:28 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/08 07:23:40 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			all_flag_check(char **array, char *options)
{
	int		i;

	i = 0;
	if (!ft_strchr(options, 'a'))
		while (array[i][0] == '.')
			i++;
	return (i);
}

void		forward_print(char *target, char **array, char *options, int max)
{
	int		i;

	i = 0;
	ft_printf("\n%s/ : \n\n", target);
	if (ft_strchr(options, 'l'))
		ft_printf("Total : %d\n\n", max);
	while (array[i])
	{
		if (!ft_strchr(options, 'a') && array[i][0] == '.')
			;
		else
			print_type(target, array[i], options);
		i++;
	}
	ft_printf("\n");
}

void		reverse_print(char *target, char **array, char *options, int max)
{
	int		size;

	size = ft_arraylen(array) - 1;
	ft_printf("\n%s/ : \n\n", target);
	if (ft_strchr(options, 'l'))
		ft_printf("Total : %d\n\n", max);
	while (size >= 0)
	{
		if (!ft_strchr(options, 'a') && array[size][0] == '.')
			;
		else
			print_type(target, array[size], options);
		size--;
	}
}

void		printing(char *target, char **array, char *options)
{
	struct stat		total;
	int				max;

	lstat(target, &total);
	max = size(target, options);
	if (ft_strchr(options, 'l'))
	{
	//	ft_printf(" %s\n", target);
	//	ft_printf("Total : %d\n\n", max);
	}
	if (ft_strchr(options, 'r'))
		reverse_print(target, array, options, max);
	else
		forward_print(target, array, options, max);
}
