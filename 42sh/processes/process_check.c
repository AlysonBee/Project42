/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:58:13 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/18 18:04:37 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int				process_checker(char **env, char *str)
{
	char		*str;
	int			i;

	i = 0;
	if (str[0] == '/')
	{
		if (access(str, F_OK | X_OK)) 
	}

}
