/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:07:38 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 12:07:51 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*join(char *s1, char *s2)
{
	char	*new;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	new = (char*)malloc(sizeof(char) * size + 1);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	new[size] = '\0';
	return (new);
}
