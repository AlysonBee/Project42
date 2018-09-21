/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanity_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:05:12 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 12:05:13 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "client.h"

int			error_message(char *arg)
{
	if (ft_strcmp(arg, "/who") == 0 ||
		ft_strcmp(arg, "/join") == 0 ||
		ft_strcmp(arg, "/leave") == 0)
	{
		printf("server commands unavailable locally\n");
		printf("only command available locally : /connect\n");
		return (-1);
	}
	return (1);
}

int			valid_connect(char *str)
{
	if (count_args(str) == 2)
		return (1);
	else
	{
		printf("Error : bad argument count\n");
		return (-1);
	}
}

int			argument_check(char *test_file)
{
	char	**arguments;
	int		ret;

	ret = -1;
	arguments = split(test_file, ' ');
	if (arguments[0][0] == '/')
	{
		if ((ret = error_message(arguments[0])) == -1)
			;
		else
			ret = valid_connect(test_file);
	}
	if (ret == -1)
		printf("Error : invalid argument error\n");
	free2d(arguments);
	return (ret);
}

int			sanity_checks(char *input)
{
	char	*test_str;
	int		flag;

	flag = -1;
	test_str = strtrim(input);
	if (count_args(test_str) > 0)
		flag = argument_check(test_str);
	else
		printf("Error : invalid argument count\n");
	free(test_str);
	return (flag);
}
