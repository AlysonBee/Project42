/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coming_soon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 07:52:38 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/30 07:53:40 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		coming_soon(char buffer[])
{
	if (ft_strstr(buffer, "/join") ||
			ft_strstr(buffer, "/leave"))
	{
		printf("Coming soon...\n");
		return (1);
	}
	return (0);
}
