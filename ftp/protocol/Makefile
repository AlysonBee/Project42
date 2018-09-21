



PROTOCOL = protocol.a

UNI = assemble_message.c message_protocol.c generic_functions_shared.c \
	  unpacking.c file_segmentation.c file_transfer.c

UNI_O = $(UNI:.c=.o)

$(PROTOCOL):
	gcc -Wall -Werror -Wextra -c $(UNI) 
	ar rc $(PROTOCOL) $(UNI_O)

all: $(PROTOCOL)

clean:
	rm -f $(UNI_O)

fclean:
	rm -f $(UNI_O)
	rm -f $(PROTOCOL)

re: fclean all
