# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 12:58:40 by vcavalca          #+#    #+#              #
#    Updated: 2021/07/06 13:22:52 by vcavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

FT_FILES = ft_strchr ft_isdigit ft_strlen

RUN_DIR = ./
RUN = $(addprefix $(RUN_DIR), $(addsuffix .c, $(FT_FILES)))

RUN_DIR_O = ./
RUN_O = $(addprefix $(RUN_DIR_O), $(addsuffix .o, $(FT_FILES)))

.c.o: $(RUN)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(RUN_O)
	$(AR) $@ $^

all: $(NAME)

clean: 
	$(RM) $(RUN_O) $(RUN_O_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
