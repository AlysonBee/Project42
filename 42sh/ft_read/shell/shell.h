/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:37:53 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/20 10:38:24 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include "../libft/libft.h"
# include "printf/includes/ft_printf.h"

typedef struct			s_echosub
{
	char				*str;
	struct s_echosub	*next;
}						t_echosub;

/*
 ** section for echo and subshell echo bonus 
 */

void					free_2d_array(void** array);
void					free_echo(t_echosub *head);
t_echosub				*dynamic_echo_list(t_echosub *head, char *words);
void					echo_subshell(char **envp, int flag, char *first, char stop);
void					aly_echo(char *str, char **envp);
void					print_echo(t_echosub *head);
t_echosub				*add_echo(t_echosub *head, char *words);
t_echosub				*new_echo(char *words);

/*
 ** Seciont for builtins env and cd and making them work together
 */

char					**ft_cd(char **env, char *test, int *status);
char					**ft_setenv(char **envp, char *to_set, int *status);
void					ft_env(char **envp);
char					**ft_unsetenv(char **env, char *to_unset, int *status);



#endif
