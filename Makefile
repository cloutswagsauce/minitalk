# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 18:17:13 by lfaria-m          #+#    #+#              #
#    Updated: 2024/11/16 14:10:47 by lfaria-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SERVER = server
CLIENT = client

# Source files
SERVER_SRC = server.c
CLIENT_SRC = client.c

# Object files
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = includes/libft

LIB = $(LIB_DIR)/libft.a

AR = ar rcs
RM = rm -f 

LIB_FLAGS = -L $(LIB_DIR) -lft

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIB_FLAGS) -o $(SERVER)
$(CLIENT): $(CLIENT_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIB_FLAGS) -o $(CLIENT)

%.o: %.c 
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

$(LIB):
	make -C $(LIB_DIR)

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
	make -C $(LIB_DIR) clean


fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re