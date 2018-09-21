/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:33:17 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/29 07:24:34 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../irc_client/client.h"
#include "circle.h"

t_circ		init_circular(size_t size)
{
	t_circ	rbuf;

	rbuf.written = 0;
	rbuf.base = 0;
	rbuf.current = 0;
	rbuf.trav = 0;
	rbuf.buffer_size = size;
	ft_bzero(rbuf.buffer, size);
	return (rbuf);
}

int			send_buffer(t_circ *round_buffer, int fd)
{
	char	buffer[4096];
	size_t	i;
	int		discon;

	i = 0;
	ft_bzero(buffer, 4096);
	while (round_buffer->base != round_buffer->trav)
	{
		if (round_buffer->base == round_buffer->buffer_size)
			round_buffer->base = 0;
		buffer[i] = round_buffer->buffer[round_buffer->base];
		i++;
		round_buffer->base++;
	}
	if (ft_strstr(buffer, "/disconnect"))
		discon = 1;
	else
		discon = 0;
	send(fd, buffer, i, 0);
	return (discon);
}

int			read_circle(t_circ *round_buffer, char content[],
		int fd)
{
	int		discon;

	write_circle(round_buffer, content);
	discon = send_buffer(round_buffer, fd);
	ft_bzero(content, 512);
	return (discon);
}

void		write_circle(t_circ *round_buffer, char content[])
{
	size_t	size;
	size_t	count;

	count = 0;
	size = ft_strlen(content);
	round_buffer->base = round_buffer->trav;
	while (count < size)
	{
		if (round_buffer->trav == round_buffer->buffer_size)
			round_buffer->trav = 0;
		round_buffer->buffer[round_buffer->trav] = content[count];
		round_buffer->trav++;
		count++;
	}
	ft_strcat(round_buffer->buffer, "\n");
}

void		print_circular(t_circ *round_buffer)
{
	while (round_buffer->base != round_buffer->trav)
	{
		if (round_buffer->base == round_buffer->buffer_size)
			round_buffer->base = 0;
		write(1, &(round_buffer->buffer[round_buffer->base]), 1);
		round_buffer->base++;
	}
	round_buffer->current = round_buffer->trav;
}
