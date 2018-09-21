# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angonyam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 07:01:19 by angonyam          #+#    #+#              #
#    Updated: 2018/07/21 07:01:22 by angonyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OTOOL = otool

NM = nm

all:
	make -C $(OTOOL)
	make -C $(NM)

nm:
	make -C $(NM)

otool:
	make -C $(OTOOL)

clean:
	make clean -C $(NM)
	make clean -C $(OTOOL)

clean_nm:
	make clean -C $(NM)

clean_otool:
	make clean -C $(OTOOL)

fclean:
	make fclean -C $(NM)
	make fclean -C $(OTOOL)

fclean_nm:
	make fclean -C $(NM)

fclean_otool:
	make fclean -C $(OTOOL)

re: fclean all

re_nm: fclean_nm nm

re_otool: fclean_otool otool
