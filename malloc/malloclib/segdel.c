/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:23:09 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/22 17:27:59 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloclib.h"

char		*segment_del(char *str)
{
	int		*start_end;
	char	*newstring;

	start_end = update_memory_record(str);
	newstring = delete_segment(start_end[0], start_end[1] + 1, str);
	return (newstring);
}
