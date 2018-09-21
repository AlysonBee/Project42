# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angonyam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 15:54:47 by angonyam          #+#    #+#              #
#    Updated: 2018/07/31 15:55:02 by angonyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


EXEC = ../ft_server

SRC = cd_admin.c handle_cd.c server.c server_shell.c handle_output.c  server_op.c ../shared.c ../protocol/*.c 

OBJ = *.o

LIB = ../libft/libft.a

all:
	make -C ../libft
	gcc -c -Wall -Werror -Wextra $(SRC)
	gcc -o $(EXEC) $(OBJ) $(LIB)

clean:
	make clean -C ../libft
	rm -f $(OBJ)

fclean:
	make fclean -C ../libft
	rm -f $(OBJ)
	rm -f $(EXEC)

re: fclean all
