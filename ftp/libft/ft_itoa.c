/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 07:40:40 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/02 07:41:31 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			num_len(int num)
{
	int		i;

	i = 0;
	while (num)
	{
		i++;
		num /= 10;
	}
	return (i);
}

char		*ft_itoa(int num)
{
	char	*number;
	int		size;

	number = (char*)malloc(sizeof(char) * num_len(num) + 1);
	size = num_len(num);
	number[size] = '\0';
	size--;
	while (num)
	{
		number[size] = (num % 10) + '0';
		num /= 10;
		size--;
	}
	return (number);
}
