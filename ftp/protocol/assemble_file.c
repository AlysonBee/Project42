/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:21:12 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:21:14 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftp.h"

unsigned char		*write_file(unsigned char *content,
		char *message, size_t *i, size_t size)
{
	size_t		c;
	size_t		j;

	j = 0;
	c = *i;
	while (j < size)
	{
		content[c] = message[j];
		c++;
		j++;
	}
	content[c] = '\0';
	return (content);
}

unsigned char		*write_file_magic(unsigned char *content,
		char *length, char *message, size_t size)
{
	size_t		i;
	size_t		j;

	j = 1;
	i = 0;
	content = write_word_len(content, length, &i);
	content = write_magic(content, &i);
	content = write_file(content, message, &i, size);
	return (content);
}
