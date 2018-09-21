
NAME = ../client

SRC = main.c help.c client_error.c connect.c connect_error.c crash_signal.c init_client.c list.c manage_server_cluster.c run_client.c sanity_checks.c ../circular/circle.c switch.c user_prompt.c coming_soon.c

OBJ = *.o

LIB = lib/lib.a

$(NAME):
	make -C lib
	gcc -Wall -Werror -Wextra -c $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB)

all: $(NAME)

clean:
	make clean -C lib
	rm -rf $(OBJ)

fclean:
	make fclean -C lib
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all
