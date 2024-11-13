# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 18:17:13 by lfaria-m          #+#    #+#              #
#    Updated: 2024/11/13 16:47:01 by lfaria-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = minitalk

# Source files
SRCS = sources/server.c sources/client.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = includes/libft

LIB = $(LIB_DIR)/libft.a

AR = ar rcs
RM = rm -f 

LIB_FLAGS = -L $(LIB_DIR) -lft

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_FLAGS) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

$(LIB):
	make -C $(LIB_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIB_DIR) clean


fclean: clean
	$(RM) $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re