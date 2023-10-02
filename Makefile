# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fracerba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 10:31:08 by fracerba          #+#    #+#              #
#    Updated: 2023/02/23 11:40:55 by fracerba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minitalk

CLIENT = client

SERVER = server

OUT = push_swap

SRCS = client.c \
	server.c \

OBJS = ${SRCS:.c=.o}

OBJS1 = client.o

OBJS2 = server.o

CC = gcc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

LIBFT = libft

LIBFTNAME = libft.a
	
%.o: %.c
	${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make all -C ${LIBFT}
	mv ${LIBFT}/${LIBFTNAME} ${NAME}
	${CC} ${FLAGS} ${OBJS1} ${NAME} -o ${CLIENT}
	make all -C ${LIBFT}
	mv ${LIBFT}/${LIBFTNAME} ${NAME}
	${CC} ${FLAGS} ${OBJS2} ${NAME} -o ${SERVER}

all: ${NAME}

bonus:	${OBJS}
	make all -C ${LIBFT}
	mv ${LIBFT}/${LIBFTNAME} ${NAME}
	${CC} ${FLAGS} ${OBJS1} ${NAME} -o ${CLIENT}
	make all -C ${LIBFT}
	mv ${LIBFT}/${LIBFTNAME} ${NAME}
	${CC} ${FLAGS} ${OBJS2} ${NAME} -o ${SERVER}

clean: 
	${RM} ${OBJS}
	make clean -C ${LIBFT}

fclean: clean 
	${RM} ${NAME}
	make fclean -C ${LIBFT}

re: fclean all
