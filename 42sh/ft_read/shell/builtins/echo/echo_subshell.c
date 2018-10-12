/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:56:42 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/17 12:42:08 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

void			run_list(t_echosub *head, char **envp)
{
	t_echosub	*trav;

	trav = head;
	while (trav)
	{
		aly_echo(trav->str, envp);
		trav = trav->next;
	}
	free_echo(head);
}

void			echo_subshell(char **envp, int flag, char *first, char stop)
{
	t_echosub	*head;
	t_echosub	*trav;
	char		*echo_shell;
	char		*str;
	char		catch;

	head = new_echo(first);
	trav = head;
	catch = (flag == 1 ? '\'' : '\"');
	echo_shell = (flag == 1 ? ft_strdup("quote>") : ft_strdup("dquote>"));
	while ('e')
	{
		ft_printf("%s", echo_shell);
		str = (char*)ft_memalloc(sizeof(char) * 1000);
		read(0, str, 1000);
		trav = add_echo(head, str);
		trav = head;
		if (ft_strchr(str, catch))
			break ;
		free(str);
	}
	run_list(head, envp);
}






