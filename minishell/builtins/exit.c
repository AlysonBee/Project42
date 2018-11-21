/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 10:37:30 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/13 16:51:38 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void		ft_exit(char *input, char **environment)
{
	ft_delarray((void**)environment);
	free(input);
	ft_putstr("\n\n      [Process Complete]\n\n");
	exit(1);
}
