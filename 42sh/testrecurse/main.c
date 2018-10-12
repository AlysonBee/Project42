/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:03:23 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/12 11:11:04 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../shell.h"
#include <dirent.h>
#include <stat/type.h>

typedef struct 			folders
{
	char				*name;
	struct folders		*next;
}						t_fold;

t_fold					*new_folder(char *file)
{
	t_fold				*new;

	new = (t_fold *)malloc(sizeof(t_fold));
	new->name = ft_strdup(file);
	new->next = NULL;
	return (new);
}

t_fold				*add_folder(t_fold *head, char *file)
{
	t_fold			*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_fold *)malloc(sizeof(t_fold));
	trav->next->name = ft_strdup(file);
	trav->next->next = NULL;
	return (trav);
}

t_fold			*dynamic(t_fold *head, char *to_add)
{
	t_fold		*trav;

	trav = head;
	if (trav == NULL)
	{
		trav = new_folder(to_add);
		head = trav;
	}
	else
	{
		trav = add_folder(head, to_add);
		trav = head;
	}
	return (trav);
}

void	recures(char *file)
{
	DIR					*dp;
	struct stat			info;
	struct dirent		*direc;
	t_fold				*head;
	t_fold				*trav;

	if (!(dp = opendir(file)))
		return ;
	while ((direc = readdir(dp)))
	{
		lstat(direct, &info);
		printf("%s\n", 
	}
}












}


int		main(void)
{
	DIR		*dp;
	struct stat		*info;

}
