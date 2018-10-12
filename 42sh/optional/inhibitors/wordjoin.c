/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:15:10 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:04:12 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_read/line.h"
#include "../../shell.h"

char			*remove_last_quote(char *str, char c)
{
	int			i;

	ft_printf("%c\n", c);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
	return (str);
}

char			*remove_ticks(char *str, char c)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			str[i] = ' ';
		i++;
	}
	return (str);
}

char			*remove_n_line(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break ;
		}
		if (str[i] == ']')
			str[i] = ' ';
		i++;
	}
	return (str);
}

char			*join_first_word(char *line, char *to_join, char c)
{
	char		**connect;
	char		*new;
	char		*temp;

	connect = ft_strsplit(line, c);
	new = ft_strjoin(" ", to_join);
	temp = ft_strjoin(connect[0], to_join);
	temp = remove_ticks(temp, c);
	return (temp);
}

char			*inhibitor(char *arg, char *line)
{
	t_inhibit	*head;
	char		*str;
	t_inhibit	*trav;
	char		*cmd;

	head = NULL;
	if (&line[1])
		head = run_inhibit(head, &line[1]);
	trav = head;
	while (1)
	{
		line[0] == '\'' ? ft_putstr("quotes>") : ft_putstr("dquotes>");
		str = (char*)malloc(sizeof(char) * 4096);
		read(0, str, 4096);
		str = remove_n_line(str);
		trav = add_inhibit(head, str);
		trav = head;
		if (ft_strchr(str, line[0]))
			break ;
		free(str);
	}
	free(str);
	cmd = join_commands(head);
	return (join_first_word(arg, cmd, line[0]));
}
