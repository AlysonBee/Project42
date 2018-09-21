



SERV = ../server

SRC = broadcasting.c channel_join.c closing.c command_arg_check.c command_error_handling.c create.c create_error_handling.c default_username_gen.c disconnect_error_handling.c init_server.c io.c join_command_error.c leave.c leave_error_handling.c leave_message.c msg.c nick.c nick_error.c reset_fds.c run_server.c server_comms.c server_response.c user_prompt.c userlist_depth.c who.c lib/arraylen.c lib/arraypush.c lib/charpush.c lib/count_args.c lib/free2d.c lib/free_and_null.c lib/itoa.c lib/join.c lib/read_buffer.c lib/split.c lib/sub.c  channel/create_channel.c channel/create_user.c channel/user_joining.c help.c join_error.c .debug.c

OBJ =  arraylen.o arraypush.o broadcasting.o channel_join.o charpush.o closing.o command_arg_check.o command_error_handling.o count_args.o create.o create_channel.o create_error_handling.o create_user.o default_username_gen.o disconnect_error_handling.o free2d.o free_and_null.o init_server.o io.o itoa.o join.o join_command_error.o leave.o leave_error_handling.o leave_message.o msg.o nick.o nick_error.o read_buffer.o reset_fds.o run_server.o server_comms.o server_response.o split.o sub.o user_joining.o user_prompt.o userlist_depth.o who.o help.o join_error.o .debug.o

LIB = lib/lib.a

$(SERV):
	make all -C lib
	gcc -Wall -Werror -Wextra -c $(SRC)
	gcc -o $(SERV) $(OBJ) $(LIB)

all:$(SERV)

clean:
	make clean -C lib
	rm -rf $(OBJ)

fclean:
	make fclean -C lib
	rm -rf $(OBJ)
	rm -rf $(SERV)

re: fclean all
