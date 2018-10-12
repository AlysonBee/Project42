/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 10:39:46 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/08 07:11:54 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	option_checker(char *options)
{
	int		i;

	i = 0;
	while (options[i])
	{
		if (ft_strchr(OPTIONS, options[i]))
			i++;
		else
		{
			ft_printf(" flag %c - not handled\n", options[i]);
			exit(1);
		}
	}
}

int		ft_ls(char *target, char *options)
{
	t_file			*top;
	t_file			*mov;
	DIR				*dp;
	struct dirent	*file;
	char			**current;

	if (!target)
		target = ft_strdup(".");
	top = new_file(".");
	mov = top;
	if (!(dp = opendir(target)))
		return (-1);
	while ((file = readdir(dp)))
	{
		mov = add_file(top, file->d_name);
		mov = top;
	}
	current = array_construct(mov);
	if (ft_strchr(options, 't'))
		current = time_sort(current);
	printing(target, current, options);
	free_2d_array(current);
	if (ft_strchr(options, 'R'))
		recursion(target, options);
	return (0);
}

char	*create_list(char *curr, char *option)
{
	char	*new;
	char	*ret;

	new = ft_strdup(curr);
	free(curr);
	ret = ft_strjoin(new, option);
	free(new);
	return (ret);
}

int		main(int argc, char **argv)
{
	char	*commands;
	int		i;
	int		flag;

	commands = (char*)ft_memalloc(sizeof(char));
	i = 1;
	flag = 0;
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			commands = create_list(commands, &argv[i][1]);
			option_checker(commands);
			if (ft_strchr(commands, 'd'))
				home(argv[i], commands);
		}
		else
			flag = which(argv, &i, commands, argc);
		i++;
	}
	if (flag == 0 || argc == 1)
		ft_ls(NULL, commands);
	return (0);
}
