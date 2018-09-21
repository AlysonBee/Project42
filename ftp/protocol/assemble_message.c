/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:21:28 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:21:30 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftp.h"

void					unpack_test(unsigned char *content)
{
	size_t		i;

	i = 0;
	printf("message length : ");
	while (content[i] != 0x00)
	{
		if (!ft_isprint(content[i]))
			break ;
		printf("%c", content[i]);
		i++;
	}
	content += i;
	i = 0;
	printf("\nmessage delim : ");
	while (i < 4)
	{
		printf("%x", content[i]);
		i++;
	}
	content += i;
	printf("\nmessage : %s\n", content);
}

unsigned char			*write_word_len(unsigned char *content,
		char *length, size_t *i)
{
	size_t		c;
	size_t		k;

	c = *i;
	k = 0;
	while (length[k])
	{
		content[c] = length[k];
		c++;
		k++;
	}
	*i = c;
	return (content);
}

unsigned char			*write_magic(unsigned char *content,
			size_t *i)
{
	size_t		j;
	size_t		c;

	j = 1;
	c = *i;
	while (j < 5)
	{
		content[c] = j;
		c++;
		j++;
	}
	*i = c;
	return (content);
}

unsigned char			*write_message(unsigned char *content,
			char *message, size_t *i)
{
	size_t		c;
	size_t		j;

	j = 0;
	c = *i;
	while (message[j])
	{
		content[c] = message[j];
		c++;
		j++;
	}
	content[c] = '\0';
	return (content);
}

unsigned char			*write_magic_num(unsigned char *content,
			char *length, char *message)
{
	size_t		i;
	size_t		j;

	j = 1;
	i = 0;
	content = write_word_len(content, length, &i);
	content = write_magic(content, &i);
	content = write_message(content, message, &i);
	return (content);
}
