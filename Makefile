# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 13:26:51 by namohamm          #+#    #+#              #
#    Updated: 2022/05/04 13:49:40 by namohamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
CC      = gcc
CFLAGS   = -Wall -Wextra -Werror -g

SRCDIR   = srcs
OBJDIR   = srcs

OK_COLOR = \x1b[32;01m

SOURCES  =	get_next_line.c \
			get_next_line_utils.c \
			main.c ft_draw.c \
			ft_mlx_putstr.c \
			ft_color.c \
			ft_bresenham.c \
			ft_read_color.c \
			ft_split.c ft_rotate.c \
			ft_init.c \
			ft_keys.c \
			ft_putstr.c \
			ft_read_file.c \
			ft_error.c \

INCLUDES = minilibx_macos/mlx.h fdf.h

OBJECTS  = $(SOURCES:%.c=%.o)
rm = rm -f

all: $(NAME)

macbook:
	make all
	
$(OBJECTS): %.o : %.c $(INCLUDES)
	$(CC) -c $< -o $@ $(CFLAGS) 

$(NAME): $(OBJECTS)
	@$(MAKE) -C minilibx_macos
	@$(CC) -o $@ $^ $(CFLAGS) -L minilibx_macos -lmlx -framework OpenGL -framework Appkit
	@echo "$(OK_COLOR)$(NAME) Created successfully !"
clean:
	@rm -f $(OBJECTS)
	@$(MAKE) clean -C minilibx_macos

fclean: clean
	@rm -f $(NAME)
	@echo "$(OK_COLOR) full clean"

re: fclean all

.PHONY: all clean fclean re
