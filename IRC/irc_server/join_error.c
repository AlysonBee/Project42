/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:13:01 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 11:13:29 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		join_error(char buffer[])
{
	ft_bzero(buffer, 4096);
	ft_strcpy(buffer, "Error : channel doesn't exist\n");
}
