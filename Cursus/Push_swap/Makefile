# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 11:28:55 by cgelin            #+#    #+#              #
#    Updated: 2022/12/19 17:15:47 by cgelin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
HEADER		=	header_ps.h

SRCS		= 	rr_ops.c header_ps.h p_ops.c push_swap.c \
				s_ops.c r_ops.c utils.c get_data.c \
				radix.c sort_three_five.c index_parsing.c utils_longs.c
OBJS		:= $(SRCS:%.c=%.o)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	print $(OBJS) compile
			@echo "\033[31m > Done!"

compile:	
			@cc *.o -o $(NAME)

%.o:%.c		${HEADER}
			@echo "\033[36m compiling: $<"
			@$(CC) $(FLAGS) -c $< -o $@

print:		
			@echo "\033[31m ~ Compiling pipex ~"

clean:
	@echo "\033[31m > Removed all objects files <"
	@rm -rf *.o

fclean: clean
	@echo "\033[31m * Removed $(NAME) *"	
	@rm -rf $(NAME)

re: fclean all

.PHONY:		all clean fclean re