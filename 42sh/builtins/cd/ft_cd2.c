/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 07:29:38 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:05:14 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

void		cd_error(char *whereto, int *status)
{
	struct stat		info;

	*status = -1;
	if (!lstat(whereto, &info))
		ft_printf("%s : Permission denied\n", whereto);
	else
		ft_printf("%s : No such file or directory\n", whereto);
}

char		**going_home(char **env, int *status)
{
	char	*pwd;
	char	*old_pwd;
	char	**new;
	int		val;

	*status = 1;
	val = 1;
	pwd = rewrite(env, "HOME", "PWD");
	old_pwd = rewrite(env, "PWD", "OLDPWD");
	new = ft_setenv(env, pwd, &val);
	env = ft_setenv(new, old_pwd, &val);
	free(pwd);
	free(old_pwd);
	return (env);
}

char		**reverse(char **env, int *status)
{
	char	*pwd;
	char	*old_pwd;
	int		val;

	*status = 1;
	val = 1;
	pwd = rewrite(env, "OLDPWD", "PWD");
	old_pwd = rewrite(env, "PWD", "OLDPWD");
	env = ft_setenv(env, pwd, &val);
	env = ft_setenv(env, old_pwd, &val);
	free(pwd);
	free(old_pwd);
	return (env);
}

char		**regular(char **env)
{
	char	*old_pwd;
	char	*pwd;
	char	cwd[2048];
	char	**new;
	int		val;

	getcwd(cwd, 2048);
	val = 1;
	old_pwd = rewrite(env, "PWD", "OLDPWD");
	pwd = ft_strjoin("PWD=", cwd);
	new = ft_setenv(env, old_pwd, &val);
	env = ft_setenv(new, pwd, &val);
	free(old_pwd);
	free(pwd);
	return (env);
}
