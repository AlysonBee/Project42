/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altogether.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:31:54 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 11:17:22 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

char		**execution_run(char *ex, char **env, int *r, int *val)
{
	if (ft_strstr(ex, ">"))
		env = run_redirection(ex, env, val, r);
	else if (ft_strstr(ex, "echo"))
		aly_echo(ex, env, r);
	else if (ft_strchr(ex, '|') && !ft_strstr(ex, "||"))
		piping(ex, env, val, r);
	else if (ft_strstr(ex, "&&") || ft_strstr(ex, "||"))
		env = andor_management(ex, env, r);
	return (env);
}

char		*prepare(char *chain)
{
	char	*ex;

	ex = ft_strtrim(chain);
	if (ft_strlen(ex) <= 1)
	{
		free(ex);
		return (NULL);
	}
	return (ex);
}

char		**altogether(char *str, char **env, int *val, int *r)
{
	char	**chain;
	int		i;
	char	*ex;
	t_exp	*head;

	chain = ft_strsplit(str, ';');
	i = -1;
	while (chain[++i])
	{
		*r = 0;
		if (!(ex = prepare(chain[i])))
			continue ;
		if ((wordcount(ex) == 1 && ft_strchr(ex, '='))
					|| ft_strstr(str, "export"))
			env = export(ex, env, &head, r);
		else
			env = execution_run(ex, env, r, val);
		if (*r == 0)
			env = run(ex, env, val);
		free(ex);
	}
	free_2d_array((void**)chain);
	*r = 1;
	return (env);
}
