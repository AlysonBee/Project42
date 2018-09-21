# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angonyam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 07:29:10 by angonyam          #+#    #+#              #
#    Updated: 2018/08/27 07:29:19 by angonyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = irc

$(NAME):
	make -C irc_server
	make -C irc_client

all: $(NAME)

clean:
	make clean -C irc_server
	make clean -C irc_client

fclean:
	make fclean -C irc_server
	make fclean -C irc_client

re: fclean all
