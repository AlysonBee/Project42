/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backquotes2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:56:31 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 16:49:05 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

int			sn_close(int fd)
{
	return (close(fd));
}

int			last_quote(char *str, int flag)
{
	int		i;
	char	*head;

	i = 1;
	while (str[i])
	{
		if (str[i] == '`')
			return (i);
		i++;
	}
	if (flag == 1)
	{
		head = back_subshell(str);
		while (head[i])
		{
			if (head[i] == '`')
				break ;
			i++;
		}
	}
	return (i);
}

int			charcount(char *str, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char		*trim(char *str)
{
	int		i;
	char	*new;
	int		j;

	new = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			new[j] = str[i];
			j++;
			while (str[i] == ' ')
				i++;
		}
		else
		{
			new[j] = str[i];
			j++;
			i++;
		}
	}
	new[j] = '\0';
	return (new);
}

char		*neatening(char *str)
{
	char	*new;
	char	*temp;

	temp = trim(str);
	free(str);
	new = ft_strjoin(temp, " ");
	free(temp);
	return (new);
}
