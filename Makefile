NAME = server
CLIENT = client

SERVERB = server_bonus
CLIENTB = client_bonus

LIBFT = ./Libft/libft.a

OCL = client.o
OSR = server.o

OCLB = client_bonus.o
OSRB = server_bonus.o

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME) $(CLIENT) $(SERVERB) $(CLIENTB)

$(NAME): $(LIBFT) $(OSR)
	@-$(CC) $(CFLAGS) $(LIBFT) $(OSR) -o $(NAME)

$(CLIENT): $(LIBFT) $(OCL)
	@-$(CC) $(CFLAGS) $(LIBFT) $(OCL) -o $(CLIENT)

$(SERVERB): $(LIBFT) $(OSRB)
	@-$(CC) $(CFLAGS) $(LIBFT) $(OSRB) -o $(SERVERB)

$(CLIENTB): $(LIBFT) $(OCLB)
	@-$(CC) $(CFLAGS) $(LIBFT) $(OCLB) -o $(CLIENTB)

$(LIBFT):
	@-make -C ./Libft

re: fclean all

clean:
	@-rm -rf $(OCL) $(OSR) $(OCLB) $(OSRB)
	@-make clean -C ./Libft


fclean: clean
	@-rm -rf $(NAME) $(CLIENT) $(SERVERB) $(CLIENTB)
	@-make fclean -C ./Libft

.PHONY: clean fclean all bonus re