# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 15:26:48 by ptheo             #+#    #+#              #
#    Updated: 2024/09/05 18:52:19 by ptheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ./src/
SRC_CHECK	= ./src_check/

MAIN	= main.c

# FILE
FILE	 = stack.c
FILE	+= mouv.c
FILE	+= parsing.c
FILE	+= print.c
FILE	+= utils.c
FILE	+= func_split.c
FILE	+= stack_utils.c
FILE	+= algo.c
FILE	+= hope.c
FILE	+= hope_utils.c
FILE	+= simple_sort.c
FILE	+= hope_utils2.c
FILE	+= error.c
FILE	+= simple_sort_utils.c
FILE	+= post.c
FILE	+= opti.c
FILE	+= opti_utils.c
# END FILE

SRC_FILE = $(addprefix $(SRC), $(FILE))
SRC_MAIN = $(addprefix $(SRC), $(MAIN))

# FILE CHECK
FILE_CHECK	 = checker.c
FILE_CHECK	+= checker_utils.c
FILE_CHECK	+= move.c
FILE_CHECK	+= ft_strncmp.c
FILE_CHECK	+= get_next_line.c
FILE_CHECK	+= get_next_line_utils.c
# END FILE CHECK

SRC_FILE_CHECK = $(addprefix $(SRC_CHECK), $(FILE_CHECK))

OBJ      		:= $(SRC_FILE:.c=.o)
OBJ_CHECK		:= $(SRC_FILE_CHECK:.c=.o)

OBJ_MAIN		:= $(SRC_MAIN:.c=.o)

INCLUDES 		:= ./includes/

CC        := cc
FLAGS 	  := -Wall -Werror -Wextra -g3

RM   		:= rm -rf
NAME 		:= push_swap
NAME_CHECK	:= checker
MAKE 		:= make

#.c.o : 
#	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ_MAIN) $(OBJ)
		@echo "compilation of push_swap file :"
		$(CC) $(FLAGS) $(OBJ) $(OBJ_MAIN) -o $(NAME) -I$(INCLUDES)

bonus : $(NAME_CHECK)

$(NAME_CHECK) : $(OBJ_CHECK) $(OBJ)
		@echo "compilation of push_swap checker file :"
		$(CC) $(FLAGS) $(OBJ_CHECK) $(OBJ) -o $(NAME_CHECK) -I$(INCLUDES)

clean :
	$(RM) $(OBJ) $(OBJ_CHECK) $(OBJ_MAIN)

fclean :
	$(RM) $(NAME) $(NAME_CHECK) $(OBJ) $(OBJ_CHECK) $(OBJ_MAIN)

re : fclean all

.PHONY: all clean fclean re