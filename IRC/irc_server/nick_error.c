/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:02:54 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 11:02:55 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		nick_error(char buffer[], int *flag, char *error_message)
{
	ft_bzero(buffer, 4096);
	ft_strcpy(buffer, error_message);
	*flag = 1;
}
