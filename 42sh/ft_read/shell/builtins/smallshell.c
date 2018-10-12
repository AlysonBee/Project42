/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 08:10:09 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/19 18:20:50 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_read/line.h"
#include "../shell.h"

int			ft_arraylen(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char		**ft_arraydup(char **array)
{
	int				i;
	char			**new;

	i = 0;
	new = (char**)malloc(sizeof(char*) * ft_arraylen(array) + 2);
	while (new[i])
	{
		new[i] = ft_strdup(array[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

int					main(int argc, char **argv, char **envp)
{
	char			**env;
	char			*term;
	struct termios	tattr;
	char			**mycd;
	int				val;

	val = 0;
	env = ft_arraydup(envp);
	tcgetattr(STDIN_FILENO, &tattr);
	while (1)
	{
		default_mode();
		term = ft_read();
		mycd = ft_strsplit(term, ' ');

		if (strcmp(ft_strtrim(term), "exit") == 0)
			exit(1);
		if (mycd[1] == NULL)
			env = ft_cd(env, NULL, &val);
		else
			env = ft_cd(env, mycd[1], &val);
		ft_env(env);
	//	free_2d_array((void**)mycd);
		tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
		free(term);
	}
}







