# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 15:26:48 by ptheo             #+#    #+#              #
#    Updated: 2024/08/28 19:28:34 by ptheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/

# FILE
FILE     = main.c
FILE	+= stack.c
FILE	+= mouv.c
FILE	+= parsing.c
FILE	+= print.c
FILE	+= utils.c
FILE	+= func_split.c
FILE	+= stack_utils.c
FILE	+= algo.c
FILE	+= sort.c
FILE	+= new_algo.c
FILE	+= hope.c
FILE	+= hope_utils.c
# END FILE

SRC_FILE = $(addprefix $(SRC), $(FILE))

OBJ      := $(SRC_FILE:.c=.o)
INCLUDES := ./includes/

CC        := cc
FLAGS 	  := -Wall -Werror -Wextra -g3

RM   := rm -rf
NAME := push_swap
MAKE := make

#.c.o : 
#	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
		@echo "compilation of push_swap file :"
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I$(INCLUDES)

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) $(NAME) $(OBJ)

re : fclean all

.PHONY: all clean fclean re