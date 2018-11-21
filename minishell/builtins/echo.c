/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:01:51 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/15 05:19:34 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../minishell.h"

static int		printing_env_name(char *to_compare,
		char **environment, int flag)
{
	int		i;
	int		size;
	char	*temp;

	size = 0;
	i = 0;
	while (environment[i])
	{
		size = 0;
		while (environment[i][size] != '=')
			size++;
		if (strncmp(to_compare, environment[i], size) == 0)
		{
			temp = strchr(environment[i], '=');
			temp++;
			ft_putstr(temp);
			flag = 0;
			free(to_compare);
			return (size);
		}
		i++;
	}
	flag = 1;
	return (0);
}

static int		env_variable_name(char *echoing, char **environment, int *flag)
{
	char	*name;
	int		size;
	int		i;

	size = 0;
	while (echoing[size] != ' ' && echoing[size])
		size++;
	name = (char*)malloc(sizeof(char) * size);
	i = 0;
	while (i < size)
	{
		name[i] = echoing[i];
		i++;
	}
	name[i] = '\0';
	return (printing_env_name(name, environment, *flag));
}

static int		nesting(char *pointer, char **environment, int *flag, int j)
{
	int		temp;
	int		negative;

	negative = j *= -1;
	temp = env_variable_name(pointer, environment, flag);
	if (*flag == 1)
		return (negative);
	return (temp);
}

static int		print_flag(char c)
{
	write(1, &c, 1);
	return (0);
}

void			echo(char **environment, char **echoing)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	flag = 0;
	if (quotation_check(echoing, which_comma(echoing)) == -1)
		return ;
	while (echoing[++i])
	{
		j = -1;
		while (echoing[i][++j])
		{
			if (echoing[i][j] == which_comma(echoing))
				j += 1;
			else if (echoing[i][j] == '$' && ft_isalnum(echoing[i][j + 1]))
			{
				j++;
				if ((j += nesting(&echoing[i][j], environment, &flag, j)) == 0)
					break ;
			}
			echoing[i][j] ? ft_putchar(echoing[i][j]) : 0;
		}
		flag = (echoing[i] && flag == 0) ? print_flag(' ') : print_flag(' ');
	}
}
