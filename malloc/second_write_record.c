/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_write_record.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:14:14 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/23 14:15:18 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/resource.h>
#include "malloc.h"

char		test_tiny_small_large(size_t bytes_allocated)
{
	if ((int)bytes_allocated < TINY_SIZE)
		return ('T');
	else if ((int)bytes_allocated > TINY_SIZE &&
			(int)bytes_allocated <= SMALL_SIZE)
		return ('S');
	else
		return ('L');
}

int			confirm_distance(char current_memory[])
{
	int		distance;

	if (current_memory[0] == '\0')
		distance = 0;
	else
		distance = ft_strlen(current_memory);
	return (distance);
}

char		*write_memory_record(size_t bytes_allocated,
			char current_memory[])
{
	int		distance;
	int		i;
	int		count;
	char	tsl;

	distance = confirm_distance(current_memory);
	i = distance;
	count = 0;
	tsl = test_tiny_small_large(bytes_allocated);
	current_memory[i++] = tsl;
	count = number_length(bytes_allocated);
	while (count > 0)
	{
		current_memory[i + (count - 1)] = bytes_allocated % 10 + '0';
		bytes_allocated /= 10;
		count--;
	}
	return (current_memory);
}
