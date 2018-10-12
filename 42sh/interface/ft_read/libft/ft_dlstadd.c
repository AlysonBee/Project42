/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:11:09 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/09/07 10:11:40 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd(t_dlist **head, t_dlist *new)
{
	t_dlist	*ptr;

	ptr = NULL;
	if (!new || !head)
		return ;
	new->next = *head;
	if (*head)
	{
		ptr = (*head)->prev;
		(*head)->prev = new;
	}
	new->prev = ptr;
	if (ptr)
		ptr->next = new;
	*head = new;
}
