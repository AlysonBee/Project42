/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloclib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:44:52 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/23 15:46:49 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MALLOCLIB_H
# define _MALLOCLIB_H

# include <sys/mman.h>
# include <string.h>
# include <stdlib.h>

void		put_n(size_t n);
void		ft_putnbr(size_t val);
int			ft_strrchrnum(char *str, char c);
void		*ft_memcpy(void *dst, const void *src, size_t len);
char		*ft_strchr(const char *str, char c);
char		*charpush(char *str, char c);
char		*charappend(char *str, char c);
int			number_length(int number);
char		*itoa_no_malloc(int num);
char		*delete_segment(int start, int end, char *str);
int			*update_memory_record(char *str);
char		*segment_del(char *str);
void		int_to_hex(size_t number);
void		ft_putendl(char *str);
void		ft_putstr(char *str);
void		ft_putchar(char c);
void		ft_putnbr_unsigned(size_t n);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);
int			ft_isdigit(int n);

#endif
