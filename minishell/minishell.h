/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:29:10 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/17 15:11:18 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

void				echo(char **environment, char **echoing);
void				ft_env(char **environment);
char				**ft_setenv(char *to_set, char **environment);
char				**ft_unsetenv(char *to_unset, char **environment);
void				ft_exit(char *input, char **environment);
int					quotation_check(char **echoing, char quote);
char				which_comma(char **echoing);
char				**unedited_env(char **environment, char **args);
char				**edited_env(char **environment, char **args);

char				**ft_cd(char *whereto, char **environment);
int					handle_access(char *whereto);

void				free_2d_array(void **array);
int					ft_2d_array_len(char **array);
char				**ft_arraydup(char **array);
void				ft_putarray(char **array);
char				*get_line(int fd);
int					ft_isspace(char c);
int					wordcount(char *str);
void				ft_delarray(void **array);
char				*strjoin(char *s1, char *s2);
char				*get_word(char **env, char *to_find);
char				*tabspace(char *str);

char				**how_many_commands(char *str, char **envi, int *flag);
char				**multiple_commands(char *line, char **envi, int *flag);
char				**env_commands(char **commands, char **environment);

char				**process(char *args, char **environment);
void				handler(int code);
void				quit_handler(void);

#endif
