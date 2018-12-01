



EXE 	= Matt_Daemon

SRC 	= daemon_process.c \
		  init.c \
		  listening.c \
		  main.c \
		  process_list_handling.c \
		  select.c

OBJ		= $(SRC:.c=.o)

SRCDIR	= src/

OBJDIR	= obj/

SRCS 	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))

all:
	gcc -c $(SRCS)
	gcc -o $(EXE) $(OBJ)
	mv $(OBJ) $(OBJDIR)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(EXE)

re: fclean all
