
EXEC = ft_ping

SRC = src/main.c \
	  src/get_address_info.c \
	  src/help.c \
	  src/pack_msg.c \
	  src/ping.c \
	  src/receive_message.c \
	  src/signals.c \
	  src/summary.c \
	  src/unpack_message.c

OBJ = main.o \
	  get_address_info.o \
	  help.o \
	  pack_msg.o \
	  ping.o \
	  receive_message.o \
	  signals.o \
	  summary.o \
	  unpack_message.o 

LIB = alylibc/lib.a

all:
	make -C alylibc
	gcc -Wall -Werror -Wextra -c $(SRC)
	mkdir obj
	gcc -o $(EXEC) $(OBJ) $(LIB)
	mv $(OBJ) obj

clean:
	make clean -C alylibc
	rm -f obj

fclean:
	make fclean -C alylibc
	rm -f obj
	rm -f $(EXEC)

re: fclean all

