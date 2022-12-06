# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 11:28:55 by cgelin            #+#    #+#              #
#    Updated: 2022/12/06 13:24:17 by cgelin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
HEADER		=	header_ps.h

SRCS		= 	down_rotate_ops.c ft_split.c header_ps.h push_ops.c push_swap.c  switch_ops.c up_rotate_ops.c utils.c

OBJS		:= $(SRCS:%.c=%.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	print $(OBJS) compile
			@echo "\033[31m > Done!"

compile:	
			@gcc down_rotate_ops.o ft_split.o push_ops.o push_swap.o switch_ops.o up_rotate_ops.o utils.o -o $(NAME)

$(OBJS): 	%.o:%.c ${HEADER}
			@echo "\033[36m compiling: $<"
			@$(CC) $(CC_FLAGS) -c $< -o $@

print:		
			@echo "\033[31m ~ Compiling pipex ~"

clean:
	@echo "\033[31m > Removed all objects files <"
	@rm -rf *.o *.o

fclean: clean
	@echo "\033[31m * Removed $(HEADER) *"	
	@rm -rf $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus