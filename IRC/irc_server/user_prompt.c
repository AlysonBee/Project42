/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:01:40 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 11:01:41 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		create_prompt(t_user *curr_user,
		char *channel_name)
{
	char	prompt[4096];

	ft_bzero(prompt, 4096);
	ft_strcpy(prompt, "<");
	ft_strcat(prompt, channel_name);
	ft_strcat(prompt, ">");
	ft_strcat(prompt, "(");
	ft_strcat(prompt, curr_user->username);
	ft_strcat(prompt, ") : ");
	ft_strcat(prompt, curr_user->buffer);
	ft_strcat(prompt, "\n\0");
	ft_bzero(curr_user->buffer, 4096);
	ft_strcpy(curr_user->buffer, prompt);
}
