# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose <jose@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 17:43:43 by jose              #+#    #+#              #
#    Updated: 2023/04/13 12:47:05 by jose             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

CFLAGS_OBJ = -Wall -Wextra -Werror -c -g

RM = rm -f

C_FILES =	main.c \
			events.c \
			events_utils.c \
			events_utils2.c \
			events_utils3.c \
			free.c \
			window.c \
			window_utils.c \
			window_utils2.c \
			window_utils3.c \
			window_utils4.c \
			error.c \
			draw.c \
			draw_utils.c

C_FILES_BONUS = main.c

SRC = $(addprefix src/, $(C_FILES))

BONUS = $(addprefix bonus/, $(C_FILES_BONUS))

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

INC = -I includes/

LIB = -L. -lft

MLBX = libmlx.a -Iinclude -ldl -lglfw -pthread -lm -lmlx -lXext -lX11

NAME = fractol

all : $(NAME)

libft.a :
			make bonus -C libft
			
libmlx.a :
			make -C mlx42

%.o : %.c
			$(CC) $(CFLAGS_OBJ) $< -o $@ $(INC)

.mandatory : libft.a libmlx.a $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB) $(MLBX)
			touch $@
			$(RM) .bonus

$(NAME) : .mandatory

.bonus : libft.a libmlx.a $(OBJ_BONUS)
			$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME) $(LIB) $(MLBX)
			touch $@
			$(RM) .mandatory

bonus : .bonus

clean :
		make clean -C libft
		make clean -C mlx42
		$(RM) src/*.o
		$(RM) bonus/*.o

fclean : clean
		$(RM) $(NAME) libft.a libmlx.a .mandatory .bonus

re : fclean all

.PHONY : all fclean clean re bonus