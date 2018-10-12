/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 08:10:09 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/20 09:50:21 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "line.h"
#include <stdlib.h>
#include <string.h>
#include "../../shell.h"

int		ev_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**ft_arraydup(char **array)
{
	int		i;
	char	**new;

	new = (char**)malloc(sizeof(char*) * ev_size(array) + 1);
	i = 0;
	while (array[i])
	{
		new[i] = ft_strdup(array[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("array is %s\n", array[i]);
		i++;
	}
}




int		main(int argc, char **argv, char **envp)
{
	char	*str;
	char	*term;
	char	**two;
	int		val;
	struct termios	tattr;
	char	**wechat;

	val = 0;
	wechat = ft_arraydup(envp);
	ft_print_array(wechat);
	tcgetattr(STDIN_FILENO, &tattr);
	while (1)
	{
		ft_putstr("$>");
		default_mode();
		term = ft_read();
		//str = ft_strdup(term);
		//two = ft_strsplit(str, ' ');
		//wechat = ft_cd(wechat, NULL, &val);
		//ft_print_array(wechat);
		if (strstr(term, "exit"))
			exit(1);
		tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
		free(term);
	}
}







