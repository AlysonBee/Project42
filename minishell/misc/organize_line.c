/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 07:34:30 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/17 04:16:46 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minishell.h"

char		*line_parsing(char *new, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			new[j] = ' ';
			j++;
			i++;
			while (ft_isspace(str[i]))
				i++;
		}
		else
		{
			new[j] = str[i];
			i++;
			j++;
		}
	}
	new[i] = '\0';
	return (new);
}

char		*organize(char *str)
{
	int		i;
	int		size;
	char	*new;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			i++;
			size++;
			while (ft_isspace(str[i]))
				i++;
		}
		else
		{
			i++;
			size++;
		}
	}
	new = (char*)malloc(sizeof(char) * size);
	return (line_parsing(new, str));
}
