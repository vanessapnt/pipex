# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 11:03:53 by varodrig          #+#    #+#              #
#    Updated: 2024/10/08 12:29:20 by varodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################################

## ARGUMENTS

NAME			= pipex
FLAGS			= -Wall -Wextra -Werror
CC				= gcc

###########################################
## SOURCES

SRCS			= pipex.c toolbox.c
OBJS			= ${SRCS:.c=.o}
HEADER			= pipex.h

###########################################
## RULES

all: ${NAME}

${NAME}: ${OBJS}
		@echo "Compiling libft..."
		@make re -C ./libft
		@${CC} ${OBJS} -Llibft -lft -o ${NAME}
		@echo "Pipex compiled"

%.o: %.c ${HEADER}
		@${CC} ${FLAGS} -c $< -o $@

clean:
		@make clean -C ./libft
		@rm -f ${OBJS}
		@echo pipex CLEAN DONE

fclean:	clean
		@make fclean -C ./libft
		@rm -f ${NAME}
		@echo pipex FCLEAN DONE

re: fclean all
		@echo pipex RE DONE

.PHONY: all clean fclean re