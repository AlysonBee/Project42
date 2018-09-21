# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angonyam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 15:54:35 by angonyam          #+#    #+#              #
#    Updated: 2018/07/31 15:54:40 by angonyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server


all:
	make -C client
	make -C server

clean:
	make clean -C client
	make clean -C server

fclean:
	make fclean -C client
	make fclean -C server

re: fclean all
