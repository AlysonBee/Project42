/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listening.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 09:34:54 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 16:39:03 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*mod_strjoin(char *s1, char *s2)
{
	char	*new;

	new = (char*)ft_memalloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(new, s1);
	free(s1);
	ft_strcat(new, s2);
	return (new);
}

char		*listening(void)
{
	char	*str;
	char	*file;

	str = NULL;
	while (1)
	{
		file = ft_strnew(2);
		read(0, file, 1);
		if (ft_strchr(file, '\n'))
			break ;
		if (str == NULL)
		{
			str = ft_strdup(file);
			free(file);
		}
		else
		{
			str = mod_strjoin(str, file);
			free(file);
		}
	}
	free(file);
	return (str);
}

char		*setting_up(char **env)
{
	char	*str;
	char	*temp;

	str = listening();
	ft_printf("", str);
	if (!str)
		return (NULL);
	str = quote_sanitization(str);
	if (ft_strchr(str, '`') || ft_strchr(str, '\'')
		|| ft_strchr(str, '\"'))
	{
		temp = modified_string(str, env);
		free(str);
		str = ft_strdup(temp);
		free(temp);
	}
	return (str);
}

char		*handling_exports(char *str, t_exp **head)
{
	str = export_to_print(str, head);
	if (!str)
	{
		ft_printf("42sh : bad pattern near '}'");
		return (NULL);
	}
	return (str);
}

char		**subshell_checker(char *temp, char **env, int *val)
{
	if (!(temp = check_subshell(temp)))
	{
		free(temp);
		return (env);
	}
	env = subshell(temp, env, val);
	return (env);
}
