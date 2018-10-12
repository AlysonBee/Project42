/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:29:08 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/17 14:51:27 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

int			whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' ||
			c == '\n' || c == '\f');
}

void		print(char *str, char **env)
{
	int		i;
	int 	j;
	char	*chr;
	char	**new;

	chr = NULL;
	i = 0;
	while (env[i])
	{
		new = ft_strsplit(env[i], '=');
		if (ft_strcmp(str, new[0]) == 0)
		{
			chr = ft_strchr(env[i], '=');
			chr++;
			break ;
		}
		free_2d_array((void**)new);
		i++;
	}
	if (chr == NULL)
		ft_printf(" ");
	else
		ft_printf("%s", chr);
}

int			enviroprint(char *str, int i, char **env)
{
	int		j;
	char	*envir;
	char	*chr;
	int		sub;

	sub = 0;
	i++;
	j = i;
	while (str[j] && !whitespace(str[j]) && str[j] != '\"' && str[j] != '\'')
	{
		sub++;
		j++;
	}
	envir = ft_strsub(str, i, sub);
	print(envir, env);
	return (sub);
}

int			quotes(char *str, int i, char **env, int f)
{
	char	flag;
	int		j;
	int		sub;

	j = 0;
	flag = (f == 1 ? '\'' : '\"');
	i++;
	while (str[i])
	{
		if (str[i] == flag)
		{
			j++;
			break ;
		}
		else if (str[i] == '$' && (flag == '\"'|| flag == '\''))
		{
			i += enviroprint(str, i, env);
			j += 2;
		}
		else
			ft_printf("%c", str[i]);
		i++;
		j++;
	}
	if (!ft_strchr(&str[i], '$') && !ft_strchr(&str[i], '\'') 
			&& !ft_strchr(&str[i], '\"'))
		return (-1);
	j++;
	return (j);
}

void		aly_echo(char *str, char **env)
{
	int		i;
	int		val;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			val = quotes(str, i, env, (str[i] == '\'' ? 1 : 2));
			if (val == -1)
				return ;
			i += val;
		}
		else if (str[i] == '$')
			i += enviroprint(str, i, env);
		else 
			ft_printf("%c", str[i]);
		i++;
	}
	ft_printf("\n");
}

char		*rewrite(char *str, int flag)
{
	int		i;
	int		catch;
	char	val;

	val = (flag == 1 ? '\'' : '\"');
	catch = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == val && catch == 0)
		{
			catch++;
			if (val == '\'')
				str[i] = '\"';
		}
		else if (catch == 1 && (str[i] == '\'' || str[i] == '\"'))
			str[i] = '\'';
		i++;
	}
	return (str);
}

int			subshellcheck(char *str, int *catch)
{
	char	flag;
	int		i;
	int		even;

	even = 0;
	i = -1;
	flag = 0;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			flag = str[i];
			*catch = (flag == '\'' ? 1 : 2);
			even++;
			break ;
		}
	}
	if (flag)
		while (str[++i])
			if (str[i] == flag)
				even++;
	return (even);
}

void	*run_echo(char **envp)
{
	char *str;
	int flag;
	int	val;

	flag = 0;
	while (1)
	{
		str = (char*)ft_memalloc(sizeof(char) * 1000);
		read(0, str, 1000);
		if ((val = subshellcheck(str, &flag)) % 2 != 0)
		{
			if (val >= 3)
				str = rewrite(str, flag);
			echo_subshell(envp, flag, str, '\'');
		}
		else
			aly_echo(str, envp);
		free(str);
	}
}

int		main(int argc, char **argv, char **envp)
{
	run_echo(envp);
	return (0);
}
