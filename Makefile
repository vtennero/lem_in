# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtennero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/04 17:57:37 by vtennero          #+#    #+#              #
#    Updated: 2018/03/04 17:57:39 by vtennero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wno-empty-body -Wno-unused -Wextra

# FLAGS = -Wall -Werror -Wextra

SANITIZE = -g3 -fsanitize=address

SRC = main.c \
		parser_links.c \
		parser_ants.c \
		parser_com.c \
		parser_rooms.c \
		graph_creator.c

PSRC = $(addprefix src/, $(SRC))

OBJ =  $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@ make -C libft/
	@ gcc -c $(FLAGS) $(PSRC) -I src/
	@ gcc -g $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)
	# @ gcc $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean:
	@ /bin/rm -f $(OBJ)
	@ make -C libft/ clean

fclean:
	@ make clean
	@ make -C libft/ fclean
	@ /bin/rm -f $(NAME)

re:
	@ make fclean
	@ make all

.PHONY: all clean fclean re