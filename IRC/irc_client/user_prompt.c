/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 07:28:02 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/27 07:28:03 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char		*zero(char *args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (args[i] == '\n')
			args[i] = '\0';
		i++;
	}
	return (args);
}

void		user_prompt(t_client *client, char *newname)
{
	char	**args;
	int		i;

	args = split(newname, ' ');
	free(client->prompt);
	i = 0;
	while (args[i])
		i++;
	i--;
	client->prompt = join(zero(args[i]), "$>");
	free2d(args);
}
