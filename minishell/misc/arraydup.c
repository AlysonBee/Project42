/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraydup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 06:29:29 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/16 01:56:23 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../minishell.h"
#include "../libft/libft.h"

char		**ft_arraydup(char **array)
{
	int		size;
	char	**new;
	int		i;

	size = ft_2d_array_len(array);
	new = (char **)malloc(sizeof(char*) * size + 1);
	i = 0;
	while (array[i])
	{
		new[i] = ft_strdup(array[i]);
		i++;
	}
	ft_delarray((void**)array);
	new[i] = NULL;
	return (new);
}
