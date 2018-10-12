/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:59:48 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/18 08:23:39 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

void		ft_exit(char *str, char **env, t_exp *head)
{
	free(str);
	if (head)
		free_export(head);
	free_2d_array((void**)env);
	ft_printf("exiting..\n");
	exit(1);
}
