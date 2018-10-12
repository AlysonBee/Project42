/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:04:32 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/07 06:58:45 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				run_l_combination(char **array, char *options, int i)
{
	struct stat		extract;
	char			**timing;

	i = 0;
	timing = ft_strchr(options, 't') ? time_sort(array) : array;
	while (timing[i])
	{
		lstat(timing[i], &extract);
		if (!S_ISDIR(extract.st_mode))
		{
			all(timing[i]);
			ft_printf(" %s\n", timing[i]);
		}
		i++;
	}
	i = 0;
	while (timing[i])
	{
		lstat(timing[i], &extract);
		if (S_ISDIR(extract.st_mode) && ft_strcmp(timing[i], ".") != 0)
			ft_ls(timing[i], options);
		i++;
	}
}

void				run_t_combination(char **array, char *options, int i)
{
	struct stat		extract;
	char			**timing;

	i = 0;
	timing = time_sort(array);
	while (timing[i])
	{
		lstat(timing[i], &extract);
		if (!S_ISDIR(extract.st_mode))
			ft_printf(" %s \n", timing[i]);
		i++;
	}
	i = 0;
	while (timing[i])
	{
		lstat(timing[i], &extract);
		if (S_ISDIR(extract.st_mode) && ft_strcmp(timing[i], ".") != 0)
			ft_ls(timing[i], options);
		i++;
	}
}

void				run_r_combination(char **array, char *options, int size)
{
	struct stat		extract;

	size = ft_arraylen(array) - 1;
	while (size >= 0)
	{
		lstat(array[size], &extract);
		if (!S_ISDIR(extract.st_mode))
			ft_printf(" %s \n", array[size]);
		size--;
	}
	size = ft_arraylen(array) - 1;
	while (size >= 0)
	{
		lstat(array[size], &extract);
		if (S_ISDIR(extract.st_mode) && ft_strcmp(array[size], ".") != 0)
		{
			ft_printf("\n\n%s : \n\n", array[size]);
			ft_ls(array[size], options);
		}
		size--;
	}
}

int					reverse_combination(int argc, char **argv,
		int size, char *options)
{
	char			**array;
	int				i;
	t_file			*head;
	t_file			*trav;
	int				pos;

	pos = argc;
	head = new_file(argv[argc]);
	trav = head;
	i = 0;
	while (argc <= size)
	{
		argc++;
		trav = add_file(head, argv[argc]);
		trav = head;
		i++;
	}
	array = array_construct(head);
	if (ft_strchr(options, 'r'))
		run_r_combination(array, options, size);
	else if (ft_strchr(options, 't'))
		run_t_combination(array, options, size);
	else if (ft_strchr(options, 'l'))
		run_l_combination(array, options, size);
	return (i);
}

int					multiples(char **array, int position,
		char *options, int argc)
{
	int				i;
	int				size;
	int				distance;

	if (ft_strlen(options) == 0 || ft_strchr(options, 'd'))
	{
		i = 0;
		while (array[++i])
			ft_printf("%s\n", array[i]);
		exit(1);
	}
	size = 0;
	i = position;
	distance = argc - position;
	return (reverse_combination(position, array, distance, options));
}
