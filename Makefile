# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 14:12:24 by tle-dref          #+#    #+#              #
#    Updated: 2024/10/18 08:07:53 by tle-dref         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I .
SRCDIR = src/
INCDIR = .

SRC = $(SRCDIR)/put_char_str.c \
		$(SRCDIR)/put_hex.c \
		$(SRCDIR)/put_nb.c \
		$(SRCDIR)/ft_printf.c \

OBJ = $(SRC:.c=.o)

HEADER = $(INCDIR)/ft_printf.h

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rs $@ $(OBJ)
	@echo "✓ Compilation des fichiers source et creation de la bibliotheque ✓"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "✓ suppression des objets ✓"

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(NAME) $(OBJBONUS)
	@echo "✔Compilation des fichiers bonus✔"
	@ar -rs $(NAME) $(OBJBONUS)

.PHONY: all clean fclean re
