/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:49:04 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/20 11:49:08 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include "../printf/includes/ft_printf.h"

char	*read_file(int fd)
{
	char	*file;
	char	*temp;
	char	*another;

	temp = (char*)malloc(sizeof(char));
	while (get_next_line(fd, &file))
	{
		another = ft_strjoin(temp, file);
		free(temp);
		temp = ft_strjoin(another, "\n");
		free(another);
		free(file);
	}
	return (temp);
}
