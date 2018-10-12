/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:37:53 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:13:01 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include "libft/libft.h"
# include "printf/includes/ft_printf.h"
# include <string.h>
# include <sys/stat.h>
/*
** Fucking updating the damn env just isn't working so I'm putting all extra
** variables that are appended into a list coz fuck you
*/

typedef struct			s_export
{
	char				*envir;
	struct s_export		*next;
}						t_exp;

typedef struct			s_andor
{
	char				*comm;
	struct s_andor		*next;
}						t_andor;

typedef struct			s_extra_vars
{
	char				*str;
	struct s_extra_vars	*next;
}						t_extr;

/*
** These functions were added to deal with my (or rather, this machine's)
** inability to handle my dynamic 2d array like a boss so fuck it.
** I just made my added functions a separate linnked list right beneath
** my 2d env array coz fuck you...
*/


typedef struct			s_env
{
	char				**env_list;
	t_extr				*pad;
	t_extr				*nxt_page;
}						t_env;

t_env					unsetting(t_env env, char *line, int *val);
t_env					env_bundle(t_env myenv, char *str, int *val, int *flag);

/*
** This section is for handling backquotes, primarily the backquote subshell
** that's spawned when the user hits ENTER and there's only 1 (or an odd
** number of) backquotes in the line
*/

typedef struct			s_back_shell
{
	char				*string;
	struct s_back_shell	*next;
}						t_back;

t_back					*new_back(char *str);
t_back					*add_back(t_back *head, char *str);
void					free_back(t_back *head);
char					*back_subshell(char *line);
char					*assembling_string(t_back *head);

/*
** The following is for handling the dreaded command chaining using && and ||
** Each node will have a command line followed a node that has either && or ||
** 		like so --> (command)->[&&/||]->(command)->[&&/||]->(command)
** Depending on the exit status of a command, 
*/

t_andor					*new_andor(char *str);
t_andor					*add_andor(t_andor *head, char *str);
void					free_andor(t_andor *head);
void					print_andor(t_andor *head);
char					**command_list(t_andor *head, char **env);
char					**run(char *str, char **env, int *val);
t_andor					*chaining(char *str, int count);
int						wordcount(char *str);

/*
** This is gonna be my final struct for hte mandatory part.
** This is going to be used to handle commas and commands on multiple lines
** It's prototype looks a lot like the others used but i wrote separate 
** prototypes to keep each of my functions/programs as standalone programs 
**, making it easier to debug.
*/

typedef struct			s_mult
{
	char				*command;
	struct s_mult		*next;
}						t_mult;

t_mult					*new_mult(char *str);
t_mult					*add_mult(t_mult *head, char *str);
void					free_mult(t_mult *head);
char					**altogether(char *str, char **env, int *val, int *r);

/*
** Struct to handle the env because a fucking dynamic array just isn't working so fuck you
*/

int						piping(char *command, char **env, int *val, int *r);

/*
** This batch of code is only used for handling piping (and fuck me this 
** was complicated as fuck.... and also fuck you...
*/

t_extr					*update_existing(t_extr *head, char *to_set, int *val);
t_extr					*remove_list(t_extr *head, char *to_unset, int *val);
void					free_list(t_extr *head);
t_extr					*new_list(char *to_set);
t_extr					*add_list(t_extr *head, char *to_set);
void					print_list(t_extr *head);

typedef struct			s_echosub
{
	char				*str;
	struct s_echosub	*next;
}						t_echosub;


/*
** section for echo and subshell echo bonus 
*/

void					ft_exit(char *str, char **env, t_exp *head);
int						process(char *argu, char **env, int *status);
char	          		**builtins(char **env, char *line, int *val);
void					free_echo(t_echosub *head);
t_echosub				*dynamic_echo_list(t_echosub *head, char *words);
void					echo_subshell(char **envp, int flag, char *first, char stop);
void					aly_echo(char *str, char **envp, int *r);
void					print_echo(t_echosub *head);
t_echosub				*add_echo(t_echosub *head, char *words);
t_echosub				*new_echo(char *words);
void					ft_echo(char **str, char **env, int *val);

/*
** Seciont for builtins env and cd and making them work togethe
*/

char					*get_line(int fd);
char					**ft_setenv(char **envp, char *to_set, int *status);
void					ft_env(char ** env, int *val);
char					**ft_unsetenv(char **env, char *to_unset, int *status);
char					**ft_cd(char **env, char *test, int *status);

int						ft_arraylen(char **array);
char					**andor_management(char *str, char **env, int *val);
char					**run_redirection(char *str, char **env, int *val, int *r);

/*
** This is the option for the export table. It's incredibly shit by the way...
*/


t_exp					*new_export(char *str);
t_exp					*add_export(t_exp **head, char *str);
void					free_export(t_exp *head);
char					**export(char *to_export, char **env, t_exp **export_table, int *val);

/*
** This next bonus is for the subshell. It's relatively easy to pull off 
** A struct with each command on each node, and a program to check if the 
** subshell
*/

typedef struct			s_subshell
{
	char				*command;
	struct s_subshell	*next;
}						t_subshell;
t_subshell				*new_command(char *line);
t_subshell				*add_command(t_subshell *head, char *line);
void					free_commands(t_subshell *head);
char					*check_subshell(char *str);

/*
** This next part is for inhibiors. We'll (again) create a linked list that will store all the commands
**, then it'll strjoin all the commands to a single string before passing it along
*/

typedef struct			s_inhibit
{
	char				*word;
	struct s_inhibit	*next;
}						t_inhibit;
t_inhibit				*new_inhibit(char *str);
t_inhibit				*add_inhibit(t_inhibit *head, char *str);
void					free_inhibit(t_inhibit *head);
t_inhibit				*run_inhibit(t_inhibit *head, char *str);
char					*inhibitor(char *arg, char *line);
char					**subshell(char *line, char **env, int *val);

/*
** My optionals are divided into 2 categories: 
** one is for bonuses that affect the env (subshell and export)
** two is for bonuses that affect the input string (inhibitors and backquotes)
*/

/*
** Option One
*/

char					**optionals(char *str, char **env, int *val);
char					*modified_string(char *str, char **env);
char					*recursive(char *str, char **env, int *val);

/*
** Experiencing problems with forking all the time.
** Seriously, this shit isn't supposed to break so what the fuck?
*/

int						smallprocess(char *first, char **env, int *status, char **args_stuff);
char					*export_to_print(char *str, t_exp **head);
t_exp					*remove_element(char *name, t_exp **head);




/*
** This is the messy part for the breaking up of all this damn code
*/

/* Taken from 42sh.c */
char					*listening(void);
/* A shorter version of listening, also taken from 42sh.c */
char					*setting_up(char **env);
char					*quote_sanitization(char *str);
char					*handling_exports(char *str, t_exp **head);
char					**subshell_checker(char *temp, char **env, int *val);
char					*input(char **env, t_exp **head);

/* The massive breakup started here */
char					*ag_function(char *comm);
void					free_2d_array(void **array);
char					**mul_function(char *comm);
char					**single_command(char *ting, char **env, int *val);
char					**multiple_commands(char *comm, char **env, int *val);
char					*handling_setenv_string(char *str);
char					**redirect(char **env, char *line, int *val, char *file);
char					*stop_block(char *str, int *t);
int						logical_op_count(char *str);
char					*whitespace_trim(char *str);
char					**andor_management(char *str, char **env, int *val);
char					*n_trim(char *str);
char					*remove_dquotes(char *str);
char					*quote_trim(char *str, char c);
char					*working_with_c(char *str, char c);
char					*quote_sanitization(char *str);
int						export_check(char *str);

/*
** Broken up from ft_cd.c into ft_cd2.c
*/

char					**going_home(char **env, int *status);
char					**reverse(char **env, int *status);
char					**regular(char **env);
void					cd_error(char *whereto, int *status);
char					*rewrite(char **env, char *what_it_was, char *what_it_must_be);

/*
** Broken up from echo.c to echo2.c
*/

int						whitespace(char c);
int						print(char *str, char **env);
int						enviroprint(char *str, char **env);
int						quotes(char *str, int i, int f);
char					*remove_tabs(char *str);

/*
** Broken up from ft_setenv.c to ft_setenv2.c
*/

char					*newline_trim(char *str);
int						ev_size(char **array);
char					*remove_zeroes(char *str);
char					*a_string(char *left, char *right, int *status);
char					**setenv_intro(char *line, int *status);

/*
** Brokein up from piping.c to piping2.c
*/

void					free_3d_array(void ***array);
char					**ft_strarrdup(char **str);
char					**ft_strjoinarr(char **str);
char					*single_string(char **array);
void					local_process(char **main_command, int *val, char **env);

/*
** Broken up from backquotes.c to backquotes2.c and backquotes3.c
*/

char					*neatening(char *str);
char					*single_str(char *str, char **env, int *val);
char					*assemble_string(t_back *head);
char					*remove_n(char *str);
char					*back_subshell(char *line);
char					*trim(char *str);
int						charcount(char *str, char c);
int						last_quote(char *str, int flag);
int						sn_close(int fd);
void					clean_exit(char *new, char **env, int *val, char *str);
char					*single_str(char *str, char **env, int *val);
char					*assemble_string(t_back *head);
char					*remove_n(char *str);
char					*back_subshell(char *line);
char					*org(char *str);
char					*backquotes(char *line, char **env, int *val);
int						export_wordcount(char *str);
t_exp 					*exporting(t_exp **head, char *str);
char					*export_create_line(char *file, char **line, int i);
char					*export_rewrite(char *var, char **line, int i, t_exp **head);
int						export_substr(char *str);
char					*k_size(char *line);
char					*export_to_print(char *str, t_exp **head);
void					erase_node(int count, t_exp **head);
char					*join_commands(t_inhibit *head);
char					*remove_newline(char *str);
char					*check_subshell(char *str);
char					*x_and_y(char *str, int x, int y);

/*
** Taken from optionals.c and optionals2.c
*/

int						wordcount_e(char *test);
char					*reorganize(char *original, char *mod);

/*
** Taken from setup.c and setup2.c
*/

char					*edit(char *str);
char					*size(char *segment, int *flag, int *i);
t_andor					*add_reset(t_andor *head, char *plc);
t_andor					*new_reset(t_andor *head, int flag);

/*
** 42sh is born
*/

char					*exit_trap(char *str, t_exp **head, char **env);
char					*input(char **env, t_exp **head);
char					**lolshell(char *str, char **env, t_exp **head, int *r);
void					ft_42sh(char **env, t_exp *head);

#endif












