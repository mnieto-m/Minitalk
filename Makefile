# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 17:51:14 by mnieto-m          #+#    #+#              #
#    Updated: 2025/08/13 19:26:45 by mnieto-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client

# Variables generales
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
MKDIR = mkdir -p
# Directorios

LIBFT_DIR = Libft/
LIBFT_BIN = Libft/bin/
LIBFT_NAME = $(LIBFT_BIN)libft.a

SRC_DIR = src/
SRC_DIR_CLIENT = $(SRC_DIR)client/
SRC_DIR_SERVER = $(SRC_DIR)server/

BIN_DIR = bin/
OBJ_DIR = $(BIN_DIR)obj/

OBJ_DIR_SERVER = $(OBJ_DIR)server/
OBJ_DIR_CLIENT = $(OBJ_DIR)client/

INCLUDE_DIR = -Iinclude

#Files
FILES_SERVER = server
FILES_CLIENT = client\
				check_argv


# FILES_ADD
SRC_CLIENT = $(addprefix $(SRC_DIR_CLIENT), $(addsuffix .c, $(FILES_CLIENT)))
SRC_SERVER = $(addprefix $(SRC_DIR_SERVER), $(addsuffix .c, $(FILES_SERVER)))

OBJ_CLIENT = $(addprefix $(OBJ_DIR_CLIENT), $(addsuffix .o, $(FILES_CLIENT)))
OBJ_SERVER = $(addprefix $(OBJ_DIR_SERVER), $(addsuffix .o, $(FILES_SERVER)))

# 1ª RULE
all: $(NAME_S) $(NAME_C)

#  SERVER Comp bin
$(NAME_S): $(OBJ_SERVER) $(LIBFT_NAME)
	$(MKDIR) $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_DIR) $(OBJ_SERVER) $(LIBFT_NAME) -o $@
	
# CLIENTE Comp bin
$(NAME_C): $(OBJ_CLIENT) $(LIBFT_NAME)
	$(MKDIR) $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_DIR) $(OBJ_CLIENT) $(LIBFT_NAME) -o $@

$(OBJ_DIR_SERVER)%.o: $(SRC_DIR_SERVER)%.c
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@
	
$(OBJ_DIR_CLIENT)%.o: $(SRC_DIR_CLIENT)%.c
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@

# Compilar la libft
$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR)

# clean OBJ
clean:
	$(RM) $(RMFLAGS) $(OBJ_DIR_CLIENT) $(OBJ_DIR_SERVER)
	$(MAKE) -C $(LIBFT_DIR) clean

# clean binary OBJ
fclean: clean
	$(RM) $(RMFLAGS) $(BIN_DIR) $(NAME_C) $(NAME_S)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Recompilar todo
re: fclean all

.PHONY: all clean fclean re