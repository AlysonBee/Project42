/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_protocol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:22:15 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:22:18 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftp.h"

unsigned char			*append_msg_len(char *message, size_t len)
{
	unsigned char	*ptr;
	char			*length;

	length = ft_itoa(len);
	ptr = mmap(0, len + ft_strlen(length) + 5,
			PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANON, -1, 0);
	if (ptr == MAP_FAILED)
	{
		printf("map failed\n");
		exit(1);
	}
	ptr = write_magic_num(ptr, length, message);
	free(length);
	return (ptr);
}

unsigned char			*message_protocol(char *message)
{
	size_t			msg_len;
	unsigned char	*ptr;

	msg_len = ft_strlen(message);
	ptr = append_msg_len(message, msg_len);
	return (ptr);
}
