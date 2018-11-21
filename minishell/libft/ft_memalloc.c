/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:39:39 by gsferopo          #+#    #+#             */
/*   Updated: 2017/09/13 18:20:55 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*memalloc;

	memalloc = (char*)malloc(sizeof(char) * size);
	if (memalloc == NULL)
		return (NULL);
	else
	{
		ft_bzero(memalloc, size);
		return (memalloc);
	}
}
