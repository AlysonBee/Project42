/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:02:11 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/15 04:29:34 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "../minishell.h"

void	ft_env(char **environment)
{
	int	i;

	i = -1;
	while (environment[++i])
		ft_putendl(environment[i]);
}
