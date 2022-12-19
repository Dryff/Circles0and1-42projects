# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: colas <colas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 11:28:55 by cgelin            #+#    #+#              #
#    Updated: 2022/12/19 12:13:12 by colas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
HEADER		=	header_ps.h

SRCS		= 	rr_ops.c header_ps.h p_ops.c push_swap.c \
				s_ops.c r_ops.c utils.c get_data.c print_tabs.c \
				radix.c sort_small.c index_parsing.c utils_2.c
OBJS		:= $(SRCS:%.c=%.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	print $(OBJS) compile
			@echo "\033[31m > Done!"

compile:	
			@cc *.o -o $(NAME)

$(OBJS): %.o:%.c ${HEADER}
			@echo "\033[36m compiling: $<"
			@$(CC) $(CFLAGS) -c $< -o $@

print:		
			@echo "\033[31m ~ Compiling pipex ~"

clean:
	@echo "\033[31m > Removed all objects files <"
	@rm -rf *.o *.o

fclean: clean
	@echo "\033[31m * Removed $(NAME) *"	
	@rm -rf $(NAME)

re: fclean all

.PHONY:		all clean fclean re