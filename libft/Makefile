# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtennero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/17 15:16:05 by vtennero          #+#    #+#              #
#    Updated: 2018/02/19 11:24:50 by vtennero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRC = ft_memcmp.c \
	  ft_strclr.c \
	  ft_strnequ.c \
	  ft_atoi.c \
	  ft_memcpy.c \
	  ft_strcmp.c \
	  ft_strnew.c \
	  ft_bzero.c \
	  ft_memdel.c \
	  ft_strcpy.c \
	  ft_strnstr.c \
	  ft_isalnum.c \
	  ft_memmove.c \
	  ft_strdel.c \
	  ft_strrchr.c \
	  ft_isalpha.c \
	  ft_memset.c \
	  ft_strdup.c \
	  ft_strsplit.c \
	  ft_isascii.c \
	  ft_putchar.c \
	  ft_strequ.c \
	  ft_isdigit.c \
	  ft_putchar_fd.c \
	  ft_striter.c \
	  ft_isprint.c \
	  ft_putendl.c \
	  ft_striteri.c \
	  ft_strstr.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_strlcat.c \
	  ft_strtrim.c \
	  ft_strjoin.c \
	  ft_strsub.c \
	  ft_putnbr_fd.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strmapi.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_strncat.c \
	  ft_toupper.c \
	  ft_memccpy.c \
	  ft_strcat.c \
	  ft_strncmp.c \
	  ft_memchr.c \
	  ft_memdup.c \
	  ft_strjoin_clr.c \
	  ft_strchr.c \
	  ft_strncpy.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_char_pos.c \
	  ft_lstnew.c \
	  ft_lstpush.c \
	  ft_lstend.c \
	  ft_lstsize.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstmap.c \
	  ft_strndup.c \
	  ft_abs.c \
	  ft_abs_ll.c \
	  ft_max.c \
	  ft_min.c \
	  ft_itoa.c \
	  ft_ltoa.c \
	  ft_lutoa.c \
	  ft_lltoa.c \
	  ft_llutoa.c \
	  ft_itoa_base.c \
	  ft_ltoa_base.c \
	  ft_lutoa_base.c \
	  ft_lltoa_base.c \
	  ft_llutoa_base.c \
	  ft_intlen.c \
	  ft_longlen.c \
	  ft_ulonglen.c \
	  ft_llonglen.c \
	  ft_ullonglen.c \
	  ft_wcharlen.c \
	  ft_wstrlen.c \
	  ft_eq_char.c \
	  get_next_line.c

FT_PRINTF_SRC = ft_printf/ft_printf.c \
	   ft_printf/ft_format.c \
	   ft_printf/ft_create_params.c \
	   ft_printf/ft_set_params.c \
	   ft_printf/ft_override_params.c \
	   ft_printf/ft_override_length.c \
	   ft_printf/ft_prop_cast.c \
	   ft_printf/ft_is_s.c \
	   ft_printf/ft_is_d.c \
	   ft_printf/ft_is_c.c \
	   ft_printf/ft_is_u.c \
	   ft_printf/ft_is_o.c \
	   ft_printf/ft_is_p.c \
	   ft_printf/ft_is_x.c \
	   ft_printf/ft_is_cap_s.c \
	   ft_printf/ft_is_s_perc.c \
	   ft_printf/ft_unicode.c \
	   ft_printf/ft_precision.c \
	   ft_printf/ft_width.c \
	   ft_printf/ft_prepend_or_append.c \
	   ft_printf/ft_left_or_right.c \
	   ft_printf/ft_print_buffer.c \

FT_PRINTF_OBJ = ft_printf.o \
	   ft_format.o \
	   ft_create_params.o \
	   ft_set_params.o \
	   ft_override_params.o \
	   ft_override_length.o \
	   ft_prop_cast.o \
	   ft_is_s.o \
	   ft_is_d.o \
	   ft_is_c.o \
	   ft_is_u.o \
	   ft_is_o.o \
	   ft_is_p.o \
	   ft_is_x.o \
	   ft_is_cap_s.o \
	   ft_is_s_perc.o \
	   ft_unicode.o \
	   ft_precision.o \
	   ft_width.o \
	   ft_prepend_or_append.o \
	   ft_left_or_right.o \
	   ft_print_buffer.o \

OBJ = $(SRC:.c=.o) $(FT_PRINTF_OBJ)

HEADER = /libft.h

FT_PRINTF_HEADER = ft_printf/ft_printf.h

all: $(NAME)

$(NAME):
	@ gcc $(FLAGS) -c $(SRC) $(FT_PRINTF_SRC) -I$(HEADER) $(FT_PRINTF_HEADER)
	@ ar rc $(NAME) $(OBJ)

clean:
	@ /bin/rm -f $(OBJ)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
