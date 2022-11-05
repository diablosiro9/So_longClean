# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 14:59:45 by dojannin          #+#    #+#              #
#    Updated: 2022/11/05 12:39:19 by dojannin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OBJ = $(SRCS:.c=.o)

CFLAGS += -Wall -Wextra -Werror # -g -fsanitize=address

SRCS = 	Parsing/checking_map.c \
		Parsing/checking_map2.c \
		Parsing/ft_split.c \
		Parsing/flood_fill.c \
		put_win.c \
		check_input.c \
		check_input2.c \
		tools_input.c \
		tools_map.c \
		tools_map2.c \
		main.c \
		tools_struct.c \
		lib_tools3.c \
		lib_tools2.c \
		check_input3.c \
		lib_tools.c \
		ft_itoa.c \
		
%.o: %.c
	$(CC) -Wall -Wextra -Werror -D BUFFER_SIZE=4096 -Imlx -c $< -o $@
	
$(NAME):		$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

all:			$(NAME)

clean:			
				rm -f $(OBJ)

fclean:			clean
					rm -f $(NAME)

norme:
					norminette -R CheckForbiddenSourceHeader $(SRCS) 

re:				fclean all

.PHONY :		all clean fclean re
