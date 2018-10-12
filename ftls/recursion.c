/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:54:26 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/08 07:26:13 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_rec		*recursive_payload(char *target, char *d_name, t_rec *head)
{
	char	*rabbithole;
	char	*new;
	t_rec	*trav;

	new = ft_strjoin(target, "/");
	rabbithole = ft_strjoin(new, d_name);
	free(new);
	trav = add_rec(head, rabbithole);
	trav = head;
	return (trav);
}

void		looper(t_rec *trav, t_rec *head, char *options)
{
	trav = trav->next;
	while (trav)
	{
		if (ft_strlen(trav->path) > 255)
			exit(1);
//		ft_printf("%s\n", trav->path);
		ft_ls(trav->path, options);
		trav = trav->next;
	}
	free_recurse(head);
}

void		recursion(char *target, char *options)
{
	struct dirent	*f;
	DIR				*dp;
	struct stat		checker;
	t_rec			*head;
	t_rec			*trav;

	head = new_rec(target);
	trav = head;
	trav = head;
	if (!(dp = opendir(target)))
		return ;
	while ((f = readdir(dp)))
	{
		if (ft_strcmp(f->d_name, ".") == 0 || ft_strcmp(f->d_name, "..") == 0)
			;
		else
		{
			stat(f->d_name, &checker);
			if (f->d_type == DT_DIR)
				trav = recursive_payload(target, f->d_name, head);
		}
	}
	looper(trav, head, options);
	closedir(dp);
}
