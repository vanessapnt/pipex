# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 14:29:23 by varodrig          #+#    #+#              #
#    Updated: 2024/10/08 12:41:25 by varodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

NAME = libft.a

LIBC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_memcmp.c ft_substr.c ft_strdup.c ft_strjoin.c ft_strtrim.c ft_calloc.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memchr.c ft_atoi.c

SRCSB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRCS = ${LIBC}

OBJS = ${SRCS:.c=.o}

OBJSB = ${SRCSB:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	@ar rcs ${NAME} ${OBJS}
#	@echo libft COMPILATION DONE

bonus: ${OBJSB} ${OBJS}
	@ar rcs ${NAME} ${OBJS} ${OBJSB}
#	@echo libft BONUS COMPILATION DONE

%.o: %.c
	@${CC} ${CFLAGS} -I includes/ -c $< -o ${<:.c=.o}

clean :
	@${RM} ${OBJS} ${OBJSB}
#	@echo libft CLEAN DONE

fclean : clean
	@${RM} ${NAME}
#	@echo libft FCLEAN DONE

re : fclean all
#	@echo libft RE DONE

.PHONY : all clean fclean re