# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 12:52:07 by vcavalca          #+#    #+#              #
#    Updated: 2021/07/06 13:26:59 by vcavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

FT_FILES = ft_printf ft_print_x ft_print_str ft_set_flag ft_print_p \
		ft_print_nbr ft_print_flag ft_print_char ft_print_n

RUN_DIR = ./
RUN = $(addprefix $(RUN_DIR), $(addsuffix .c, $(FT_FILES)))

RUN_DIR_O = ./
RUN_O = $(addprefix $(RUN_DIR_O), $(addsuffix .o, $(FT_FILES)))

.c.o: $(RUN)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(RUN_O)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $@ $^

all: $(NAME)

clean: 
	$(RM) $(RUN_O)
	make fclean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
