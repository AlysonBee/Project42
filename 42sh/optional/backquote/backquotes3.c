/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backquotes3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:57:17 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 16:51:18 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

void		clean_exit(char *new, char **env, int *val, char *str)
{
	char	**arr;

	arr = ft_strsplit(str, ' ');
	smallprocess(new, env, val, arr);
	free_2d_array((void**)arr);
	exit(1);
}

char		*single_str(char *str, char **env, int *val)
{
	int			fd[2];
	char		buffer[10000];
	ssize_t		size;
	char		*new;

	new = neatening(str);
	pipe(fd);
	if (fork() == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		clean_exit(new, env, val, str);
	}
	else
	{
		close(fd[1]);
		size = read(fd[0], buffer, 10000);
		if ((unsigned long)size > 0 && (unsigned long)size < sizeof(buffer))
			buffer[size] = '\0';
		wait(NULL);
	}
	free(new);
	return (ft_strdup(buffer));
}

char		*assemble_string(t_back *head)
{
	char	*ret;
	char	*temp;

	ret = (char*)malloc(sizeof(char));
	while (head)
	{
		temp = ft_strjoin(ret, head->string);
		free(ret);
		ret = ft_strjoin(temp, "");
		free(temp);
		head = head->next;
	}
	free_back(head);
	return (ret);
}

char		*remove_n(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
	return (str);
}

char		*back_subshell(char *line)
{
	t_back	*head;
	t_back	*trav;
	char	*add;

	head = new_back(line);
	trav = head;
	while (1)
	{
		ft_printf("bquotes>");
		add = (char*)ft_memalloc(sizeof(char) * 10000);
		read(0, add, 1000);
		add = remove_n(add);
		trav = add_back(head, add);
		trav = head;
		if (ft_strchr(add, '`'))
		{
			free(add);
			break ;
		}
		free(add);
	}
	return (assemble_string(head));
}
