# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angonyam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/04 08:47:00 by angonyam          #+#    #+#              #
#    Updated: 2017/11/06 07:10:42 by angonyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = ft_ls
libft = libft/libft.a
printf = printf/libftprintf.a
includes = $(wildcard *.h)
src = $(wildcard *.c)
obj = $(src:%.c=%.o)

all: $(name)

$(name): $(obj) $(libft) $(printf)
	gcc -g -Wall -Werror -Wextra $(obj) -o $@ $(libft) $(printf)

$(obj): %.o : %.c
	gcc -g -c -Wall -Werror -Wextra $<

$(libft):
	make -C libft

$(printf):
	make -C printf

clean:
	rm -f $(obj)

fclean:
	rm -f $(obj)
	rm -f $(libft)
	rm -f $(printf)
	rm -f $(name)

re: fclean all
