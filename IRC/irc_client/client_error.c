/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:04:12 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 12:04:15 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "client.h"

void		error_and_quit(char *function)
{
	printf("Error : %s\n", function);
	exit(1);
}
