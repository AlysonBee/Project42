/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optionals2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:30:26 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 14:37:05 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int			wordcount_e(char *test)
{
	int		i;
	int		count;
	char	*str;

	str = ft_strtrim(test);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

char		*reorganize(char *original, char *mod)
{
	char	**to_append;
	char	*ret;
	char	*temp;

	to_append = ft_strsplit(original, ' ');
	temp = ft_strjoin(to_append[0], " ");
	ret = ft_strjoin(temp, mod);
	free(temp);
	free_2d_array((void**)to_append);
	free(mod);
	return (ret);
}
