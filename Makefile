# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jralph <jralph@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 17:43:43 by jose              #+#    #+#              #
#    Updated: 2023/04/17 13:58:21 by jralph           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

CFLAGS_OBJ = -Wall -Wextra -Werror -c

RM = rm -f

C_FILES =	events.c \
			zoom_utils.c \
			zoom.c \
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
			draw_utils.c \
			mandelbrot.c \
			julia.c \
			burning_ship.c

C_FILES_BONUS = 

SRC = $(addprefix src/, $(C_FILES))

BONUS = $(addprefix src/, $(C_FILES_BONUS))

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

src/main.o : src/main.c
			$(CC) $(CFLAGS_OBJ) $< -o $@ $(INC)

src/main_bonus.o : src/main_bonus.c
			$(CC) $(CFLAGS_OBJ) $< -o $@ $(INC)

.mandatory : libft.a libmlx.a $(OBJ) src/main.o
			$(CC) $(CFLAGS) $(OBJ) src/main.o -o $(NAME) $(LIB) $(MLBX)
			touch $@
			$(RM) .bonus

$(NAME) : .mandatory

.bonus : libft.a libmlx.a $(OBJ) src/main_bonus.o
			$(CC) $(CFLAGS) $(OBJ) src/main_bonus.o -o $(NAME) $(LIB) $(MLBX)
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