# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 14:39:27 by jle-quer          #+#    #+#              #
#    Updated: 2016/03/08 13:11:56 by jle-quer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	srcs/ft_atoi.c \
			srcs/ft_bzero.c \
			srcs/ft_count.c \
			srcs/ft_count_wchar.c \
			srcs/ft_isspace.c \
			srcs/ft_itoa.c \
			srcs/ft_itoa_base.c \
			srcs/ft_power.c \
			srcs/ft_putchar.c \
			srcs/ft_putint.c \
			srcs/ft_putnbr.c \
			srcs/ft_putstr.c \
			srcs/ft_putwchar.c \
			srcs/ft_putwstr.c \
			srcs/ft_strdup.c \
			srcs/ft_strjoin.c \
			srcs/ft_strlen.c \
			srcs/ft_strnew.c \
			srcs/ft_strsplit.c \
			srcs/ft_strsub.c \
			srcs/ft_words.c \
			block_type/check_display_block_d.c \
			block_type/check_display_block_o.c \
			block_type/check_display_block_p.c \
			block_type/check_display_block_u.c \
			block_type/check_display_block_x.c \
			check_format.c \
			check_format_2.c \
			display_block.c \
			ft_printf.c \
			set_c.c \
			set_d.c \
			set_format.c \
			set_hex.c \
			set_octal.c \
			set_tag.c \
			set_p.c \
			set_s.c \
			set_u.c \
			set_wchar_s.c \
			tools.c \
			tools2.c \
			set_d_norm.c

OBJ_NAME = $(SRC_NAME:.c=.o)

NAME = libftprintf.a

INC_PATH = ./

CC = gcc

CFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@ar rc $(NAME) $(OBJ_NAME)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH)

clean:
	@rm -rf $(OBJ_NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
