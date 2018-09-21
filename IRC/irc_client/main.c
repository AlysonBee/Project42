/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:05:00 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 12:05:01 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		main(int argc, char **argv)
{
	t_client client;

	client.servers = NULL;
	init_client(&client, argc, argv);
	run_client(client);
	return (0);
}
