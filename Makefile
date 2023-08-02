# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 12:21:16 by cacarval          #+#    #+#              #
#    Updated: 2023/08/02 13:21:50 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = srcs/push_swap.c srcs/movements.c srcs/movements2.c \
		srcs/list_utils.c srcs/sort_utils.c srcs/sort_five.c \
		srcs/sort_big.c srcs/strat.c srcs/sort_three.c \
		srcs/errors.c srcs/check.c srcs/sort_big2.c 
OBJS = ${SRC:.c=.o}
LIBFT_DIR = libft
INCLUDE = -I include
LIBFT_PATH = ${LIBFT_DIR}/libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
GREEN := \033[32m
RED := \033[31m
RESET := \033[0m


.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ${LIBFT_DIR}
			${CC} ${CFLAGS} ${OBJS} ${LIBFT_PATH} -o ${NAME}
			@echo "${GREEN}push_swap was created${RESET}"

all:	${NAME}

clean:
		make clean -C ${LIBFT_DIR}
		${RM} ${OBJS}
		@echo "${RED}Objects were removed${RESET}"

fclean: clean
		make fclean -C ${LIBFT_DIR}
		${RM} ${NAME} push_swap
		@echo "${RED}push_swap was removed${RESET}"

re:	clean all

.SILENT:

