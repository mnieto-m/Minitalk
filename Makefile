# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 17:51:14 by mnieto-m          #+#    #+#              #
#    Updated: 2024/12/28 18:32:00 by mnieto-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME_C = client
#NAME_S = server

#CC = CC
#CFLAGS = -Wall -Werror -Wextra
#RM = rm 
#RMFLAGS = -RMFLAGS

#INCLUDE = 

#CLIENT =

#SERVER =

#OBJS_C = $(SRCS_C:%.c=objs/%.o)
#OBJS_S = $(SRCS_S:%.c=objs/%.o)


#all: $(NAME_C) $(NAME_S)

#$(NAME_C): $(OBJ_C)

#$(NAME_S): $(OBJ_S)

#clean :
#	$(RM) $(RMFLAGS) ${OBJ} $(LIBFT)
#fclean:
#	$(RM) $(RMFLAGS) $(NAME) $(printf) $(LIBFT)

#re : clean fclean


#.PHONY: all clean fclean re 

NAME_C = server
NAME_C = client

# Variables generales
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm
RMFLAGS = -rf
MKDIR = mkdir -p
INCLUDE = -I${INCLUDE_DIR}
# Directorios

LIBFT_DIR = Libft/
LIBFT_BIN = Libft/bin/
LIBFT_NAME = $(LIBFT_BIN)libft.a
SRC_DIR = src/
OBJ_DIR = bin/obj/
BIN_DIR = bin/
INCLUDE_DIR = include/

#Files
SERVER_DIR =


FILES = main\
		check_argv\
		checkfile_fdf\
		ft_atoi_base\
		ft_error\
		init_map\
		mlx\
		read_map

# FILES_ADD
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))

OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

# 1ª RULE
all: $(NAME)

# Comp bin
$(NAME): $(OBJ) $(LIBFT_NAME)
	$(MKDIR) $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT_NAME) -o $@

# Comp .O
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilar la libft
$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR)

# clean OBJ
clean:
	$(RM) $(RMFLAGS) $(OBJ_DIR)

# clean binary OBJ
fclean: clean
	$(RM) $(RMFLAGS) $(BIN_DIR) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Recompilar todo
re: fclean all