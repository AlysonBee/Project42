/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:29:08 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:08:05 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

void		precision_instrument(char *str, char **env)
{
	int		i;
	int		sub;
	int		start;
	char	*parse;

	sub = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			start = i;
			while (ft_isalnum(str[i]))
			{
				i++;
				sub++;
			}
			parse = ft_strsub(str, start, sub);
			print(parse, env);
		}
		ft_printf("%c", str[i]);
		i++;
	}
}

void		inhibitor_echo(char *str, char **env, int *val)
{
	char	**new;
	char	**arr;
	int		i;
	int		j;
	char	*target;

	target = ft_strchr(str, ' ');
	target++;
	new = ft_strsplit(target, '\n');
	i = 0;
	while (new[i])
	{
		arr = ft_strsplit(new[i], ' ');
		j = -1;
		while (arr[++j])
		{
			if (ft_strchr(arr[j], '$'))
				precision_instrument(arr[j], env);
			else
				ft_printf("%s ", arr[j]);
			ft_printf(" ");
		}
		ft_printf("\n");
		i++;
		*val = 1;
	}
}

int			n_line_count(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

void		aly_echo(char *word, char **env, int *r)
{
	int		i;
	char	**str;

	*r = 1;
	word = remove_tabs(word);
	if (n_line_count(word) > 1)
		return (inhibitor_echo(word, env, r));
	str = ft_strsplit(word, ' ');
	i = 1;
	while (str[i])
	{
		if (str[i][0] == '$')
			enviroprint(&str[i][1], env);
		else
			ft_printf("%s", str[i]);
		ft_putchar(' ');
		i++;
	}
	free_2d_array((void**)str);
	ft_printf("\n");
}
