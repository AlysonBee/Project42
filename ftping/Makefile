
EXEC = ft_ping

SRC = src/main.c \
	  src/get_address_info.c \
	  src/help.c \
	  src/pack_msg.c \
	  src/ping.c \
	  src/receive_message.c \
	  src/signals.c \
	  src/summary.c \
	  src/unpack_msg.c

OBJ = main.o \
	  get_address_info.o \
	  help.o \
	  pack_msg.o \
	  ping.o \
	  receive_message.o \
	  signals.o \
	  summary.o \
	  unpack_msg.o 

OBJ_DIR = obj/main.o \
	  obj/get_address_info.o \
	  obj/help.o \
	  obj/pack_msg.o \
	  obj/ping.o \
	  obj/receive_message.o \
	  obj/signals.o \
	  obj/summary.o \
	  obj/unpack_msg.o

LIB = alylibc/lib.a

all:
	make -C alylibc
	gcc -Wall -Werror -Wextra -c $(SRC)
	gcc -o $(EXEC) $(OBJ) $(LIB)
	mv $(OBJ) obj

clean:
	make clean -C alylibc
	rm -f obj/$(OBJ_DIR)

fclean:
	make fclean -C alylibc
	rm -f obj/$(OBJ_DIR)
	rm -f $(EXEC)

re: fclean all

