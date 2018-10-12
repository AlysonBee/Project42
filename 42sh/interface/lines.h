/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:38:25 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/06 14:40:28 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINES_H
# define LINES_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct			s_hist
{
	char				*stuff;
	struct s_hist		*next;
	struct s_hist		*prev;
}						t_hist;

#endif 


