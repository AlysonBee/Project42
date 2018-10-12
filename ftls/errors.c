/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:14:59 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/04 11:30:12 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			error(char *direct)
{
	struct stat		msg;

	lstat(direct, &msg);
	if (!(msg.st_mode & S_IRUSR))
	{
		perror(direct);
		return (0);
	}
	return (1);
}
