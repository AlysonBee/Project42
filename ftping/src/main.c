/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:02:21 by angonyam          #+#    #+#             */
/*   Updated: 2018/10/09 11:02:23 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftping.h"

void	init_statistics(char *hostname)
{
	g_stats.loop = 1;
	g_stats.rec = 0;
	g_stats.transm = 0;
	g_stats.total_time = 0;
	g_stats.hostname = hostname;
	g_stats.flags = NULL;
	gettimeofday(&g_stats.starttime, 0);
}

int		name_me(int argc, char **argv)
{
	int					i;

	if (argc < 2)
	{
		printf("Usage : %s <hostname>\n", argv[0]);
		exit(1);
	}
	i = 1;
	g_stats.flags = collect_flags(1, argc, argv);
	if (g_stats.flags != NULL && strchr(g_stats.flags, 'h'))
		help();
	while (i < argc)
	{
		if (argv[i][0] != '-')
			return (i);
		else
			i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	struct sockaddr_in	to;
	int					ping_sockfd;
	char				*addr_info;
	char				*arg;
	int					plc;

	if (argc < 2)
	{
		printf("Usage: %s <hostname?\n", argv[0]);
		exit(1);
	}
	plc = name_me(argc, argv);
	arg = argv[plc];
	init_statistics(arg);
	ft_memset(&to, 0, sizeof(struct sockaddr_in));
	if ((ping_sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
		error_and_exit("Error : socket()");
	if ((addr_info = get_address_info(arg)) == NULL)
		error_and_exit("Error : get_address_info()");
	to.sin_family = AF_INET;
	inet_pton(AF_INET, addr_info, &(to.sin_addr));
	printf("PING %s (%s) %d(84) bytes of data.\n", arg,
	addr_info, (int)(sizeof(t_icmp) + sizeof(t_ip) + 8));
	ping_me(addr_info, to, ping_sockfd);
}
