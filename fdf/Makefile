


EXE 	=	fdf

SRC 	= 	convert_wireframe_to_grid.c \
	  		grid_setup.c draw.c  \
			plot_coordinates.c \
			main.c \
			read_wireframe.c

SRCDIR	= 	src/
OBJDIR	=	obj/

SRCS 	= 	$(addprefix $(SRCDIR), $(SRC))
OBJS	= 	$(addprefix $(OBJDIR), $(OBJ))

OBJ 	= 	$(SRC:.c=.o)

LIB 	=	alylibc/lib.a

MLBX	=	-lmlx -framework OpenGL -framework AppKit

CFLAGS	=	-Werror -Wextra -Wall

all: $(EXE)
$(EXE):
	make -C alylibc
	gcc -c $(CFLAGS) $(SRCS)
	gcc -o $(EXE) $(OBJ) $(MLBX) $(LIB)
	mv $(OBJ) $(OBJDIR)

clean:
	make clean -C alylibc
	rm -f $(OBJS)
	rm -f $(LIB)

fclean:
	make fclean -C alylibc
	rm -f $(OBJS)
	rm -f $(LIB)
	rm -f $(EXE)

re: fclean all
