/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:33:23 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/29 07:24:43 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_H
# define CIRCLE_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_circle_io
{
	int			buffer_size;
	int			written;
	int			base;
	int			current;
	int			trav;
	char		buffer[4096];
}				t_circ;

t_circ			init_circular(size_t size);
void			print_circular(t_circ *round_buffer);
void			write_circle(t_circ *round_buffer,
				char *content);
int				read_circle(t_circ *round_buffer,
				char content[], int fd);

#endif
