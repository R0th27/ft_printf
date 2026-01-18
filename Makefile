# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/18 23:40:04 by htoe              #+#    #+#              #
#    Updated: 2026/01/19 04:50:41 by htoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -Rf
OBJS_DIR = objs

#source files
SRCS = ft_printf.c ft_printf_utils.c
OBJS = ${SRCS:%.c=${OBJS_DIR}/%.o}

#pattern rules
${OBJS_DIR}/%.o: %.c
	mkdir -p ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

all: ${NAME}

#clean up
clean:
	${RM} ${OBJS_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: fclean all re clean
