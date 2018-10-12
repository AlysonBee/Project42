/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 10:38:12 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/08 07:22:54 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <pwd.h>
# include <sys/xattr.h>
# include <time.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include "printf/includes/ft_printf.h"
# include <grp.h>
# define PATH_MAX 256
# define OPTIONS "altrRd"

typedef struct			s_files
{
	char				*info;
	struct s_files		*next;
}						t_file;

typedef struct			s_recurse
{
	char				*path;
	struct s_recurse	*next;
}						t_rec;

int						which(char **argv, int *i, char *commands, int argc);
void					single_ls(char *argv, char *options);
int						reverse_combination(int argc, char **argv,
						int size, char *options);
int						error(char *direct);
int						size(char *directory, char *options);
void					printing(char *target, char **array, char *options);
void					reverse_print(char *target, char **array,
						char *options, int max);
int						ft_ls(char *target, char *options);
void					print_file(t_file *head);
t_file					*add_file(t_file *head, char *file);
t_file					*new_file(char *file);
t_rec					*add_rec(t_rec *head, char *str);
t_rec					*new_rec(char *str);
void					recursion(char *target, char *options);
void					print_recurse(t_rec *head);
void					free_recurse(t_rec *head);
void					print_arr(char **array);
void					print_file(t_file *head);
char					**array_construct(t_file *head);
t_file					*new_file(char *file);
int						file_size(t_file *head);
void					free_files(t_file *head);
char					**time_sort(char **array);
void					all(char *file);
void					print_type(char *target, char *file,
						char *options);
int						all_flag_check(char **array, char *options);
int						multiples(char **array, int position,
						char *options, int argc);
void					home(char *argv, char *options);

#endif
