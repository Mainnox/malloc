# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akremer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 13:57:50 by akremer           #+#    #+#              #
#    Updated: 2021/11/18 16:06:04 by akremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LINK = libft_malloc.so
NAME = libft_malloc_$(HOSTTYPE).so
FLAGS = -Wall -Wextra -Werror
HEADER_PATH = includes/
HEADER_NAME = malloc.h
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))
INCLUDE_HEADER = -I ./$(HEADER_PATH)
PTHREAD = -pthread

SRC_PATH = ./srcs/
SRC_NAME = malloc.c realloc.c free.c show_alloc_mem.c block.c ft_memcpy.c ft_putnbr.c ft_putstr.c heap.c hex_dump.c calloc.c ft_strncpy.c tools.c
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = .obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

OS_NAME = $(shell uname)
ifeq ($(OS_NAME), Darwin)
else
	OS_FLAGS += -fPIC
endif

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	gcc -shared $(OS_FLAGS) $(FLAGS) -o $(NAME) $(INCLUDE_HEADER) $(OBJ)
	ln -s $(NAME) $(NAME_LINK)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)
	gcc $(FLAGS) $(OS_FLAGS) $(INCLUDE_HEADER) -o $@ -c $< $(PTHREAD)

clean:
	$(RM) -rf $(OBJ_PATH)

fclean: clean
	$(RM) -rf $(NAME)
	$(RM) $(NAME_LINK)
	$(RM) mallockiller

re: fclean all

mallockiller: $(NAME) srcs/*.c includes/*.h
	gcc $(OS_FLAGS) -I $(HEADER_PATH) -o mallockiller srcs/main.c -L . -lft_malloc 

.PHONY: all clean fclean re
