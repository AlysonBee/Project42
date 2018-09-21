# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angonyam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 15:55:07 by angonyam          #+#    #+#              #
#    Updated: 2018/07/31 15:55:18 by angonyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


EXEC = ../ft_client

SRC = client_shell_misc.c client.c receive_terminal_output.c  client_op.c ../shared.c client_shell.c handle_put_get.c \
	 ../protocol/*.c #../message_protocol.c ../unpack_message.c 

OBJ = *.o #message_protocol.o unpack_message.o

LIB = ../libft/libft.a

all:
	make -C ../libft
	gcc -g -c -Wall -Werror -Wextra $(SRC)
	gcc -o $(EXEC) $(OBJ) $(LIB)

clean:
	make clean -C ../libft
	rm -f $(OBJ)

fclean:
	make fclean -C ../libft
	rm -f $(OBJ)
	rm -f $(EXEC)

re: fclean all
