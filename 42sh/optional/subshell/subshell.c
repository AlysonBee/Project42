/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:35:11 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:00:31 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

t_subshell			*dynamic_alloc(t_subshell *head, char *line)
{
	t_subshell		*trav;

	trav = head;
	if (trav == NULL)
	{
		trav = new_command(line);
		head = trav;
	}
	else
	{
		trav = add_command(head, line);
		trav = head;
	}
	return (trav);
}

char			*remove_close(char *str)
{
	int			i;
	char		*new;

	new = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i] != ')')
	{
		new[i] = str[i];
		i++;
 	}
 	new[i] = '\0';
 	free(str);
 	return (new);
}

char			**subshell_command_tree(char *str, char **env, int *val, int *r)
{
	if (ft_strstr(str, "exit"))
		ft_exit(str, env, NULL);
	else if (ft_strchr(str, '|') && !ft_strstr(str, "||"))
		piping(str, env, val, r);
	else if (ft_strstr(str, "&&") || ft_strstr(str, "||"))
		env = andor_management(str, env, r);
	else if (ft_strstr(str, ">"))
		env = run_redirection(str, env, val, r);
	if (*r == 0)
		env = run(str, env, val);
	return (env);
}

char			**run_command(t_subshell *shell, char **env, int *val)
{
	t_subshell 	*trav;
	char		*str;
	int			r;

	r = 0;
	trav = shell;
	while (trav)
	{
		str = ft_strtrim(trav->command);
		if (ft_strchr(str, ')'))
			str = remove_close(str);
		if (ft_strchr(str, '('))
			env = subshell(str, env, val);
		if (ft_strlen(str) <= 1)
		{
			trav = trav->next;
			continue ;
		}
		else
			env = subshell_command_tree(str, env, val, &r);
		trav = trav->next;
		free(str); 
	}
	str == NULL ? 0 : free(str);
	return (env);
}

char				**subshell(char *line, char **env, int *val)
{
	t_subshell		*head;
	char			*str;

	ft_printf("", line);
	head = NULL;
	while (1)
	{
		ft_putstr("subsh> ");
		str = (char*)malloc(sizeof(char) * 4096);
		read(0, str, 4096);
		str = remove_newline(str);
		head = dynamic_alloc(head, str);
		if (ft_strchr(str, ')'))
			break ;
		free(str);
	}
	free(str);
	env = run_command(head, env, val);
	free_commands(head);
	return (env); 
}
