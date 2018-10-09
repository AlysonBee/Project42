/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpack_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:02:43 by angonyam          #+#    #+#             */
/*   Updated: 2018/10/09 11:02:44 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftping.h"

int			unpack_msg(char *buffer, int len, char *addr)
{
	int			header_size;
	t_ip		*ip;
	t_icmp		*icmp;

	ip = (t_ip *)buffer;
	header_size = 20;
	icmp = (t_icmp *)(buffer + header_size);
	printf("%d bytes from %s : icmp_seq=%d  ttl=%d ",
	len + header_size, addr, icmp->sequence, ip->ttl);
	return (0);
}
