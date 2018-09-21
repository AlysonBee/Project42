# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angonyam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 15:56:22 by angonyam          #+#    #+#              #
#    Updated: 2018/06/29 15:56:28 by angonyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_free.c \
	  decoder.c \
	  ft_malloc.c \
	  ft_realloc.c \
	  printing.c \
	  second_write_record.c \
	  setup_alloc.c \
	  show_alloc_mem.c \
	  malloclib/ft_putchar.c \
	  malloclib/ft_isdigit.c \
	  malloclib/ft_memcpy.c \
	  malloclib/ft_putstr.c \
	  malloclib/ft_strlen.c \
	  malloclib/ft_strrchrnum.c \
	  malloclib/itoa.c \
	  malloclib/numlen.c \
	  malloclib/putn.c \
	  malloclib/ft_atoi.c \
	  malloclib/ft_strchr.c \
	  malloclib/intohex.c \

OBJ = ft_free.o \
	  decoder.o \
	  ft_malloc.o \
	  ft_realloc.o \
	  printing.o \
	  second_write_record.o \
	  setup_alloc.o \
	  show_alloc_mem.o \
	  ft_putchar.o \
	  ft_isdigit.o \
	  ft_memcpy.o \
	  ft_putstr.o \
	  ft_strlen.o \
	  ft_strrchrnum.o \
	  itoa.o \
	  numlen.o \
	  putn.o \
	  ft_atoi.o \
	  ft_strchr.o \
	  intohex.o 



ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

all:
	gcc -Wall -Werror -Wextra -c $(SRC)
	ar rc libft_malloc_$(HOSTTYPE).so $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f libft_malloc_$(HOSTTYPE).so

re: fclean all







