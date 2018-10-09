/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_address_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:02:00 by angonyam          #+#    #+#             */
/*   Updated: 2018/10/09 11:02:01 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

char	*get_address_info(char *url)
{
	struct sockaddr_in		*ip_addr;
	struct addrinfo			hints;
	struct addrinfo			*result;
	int						i;
	char					hostname[100];

	memset(hostname, 0, 100);
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	if ((i = getaddrinfo(url, NULL, &hints, &result)) < 0)
	{
		printf("ft_ping: host unknown\n");
		exit(1);
	}
	ip_addr = (struct sockaddr_in *)result->ai_addr;
	inet_ntop(AF_INET, &ip_addr->sin_addr, hostname, 100);
	printf("hostname : %s\n", hostname);
	return (strdup(hostname));
}
