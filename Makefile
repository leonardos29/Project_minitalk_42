SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_SERVER = server.c \
			 libft/ft_atoi.c \
			 libft/ft_printf/ft_handle_char.c \
			  libft/ft_printf/ft_handle_hex.c \
			  libft/ft_printf/ft_handle_int.c \
			 libft/ft_printf/ft_printf.c

SRC_CLIENT = client.c \
			 libft/ft_atoi.c \

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) -o $@ $^

$(CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "Limpando os arquivos .o ..."
	@rm -f *.o libft/*.o

fclean: clean
	@echo "Limpando os arquivos .o e os executaveis ..."
	@rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re client.c