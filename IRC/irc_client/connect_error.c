/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:05:27 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 13:15:54 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		connect_error(char buffer[])
{
	if (count_args(buffer) != 2)
	{
		printf("/connect : invalid argument count\n");
		return (-1);
	}
	return (1);
}
