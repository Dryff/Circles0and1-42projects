# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 12:05:56 by cgelin            #+#    #+#              #
#    Updated: 2022/11/17 11:30:28 by cgelin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
INCS		:= ft_printf.h

SRCS		:= ft_putstr_int.c	ft_printf.c ft_print_hexa.c \
			   ft_putnbr_u.c ft_putnbr.c

OBJS		:= $(SRCS:%.c=%.o)

# Compiler options
CC			:= cc
CC_FLAGS	:= -Wall -Wextra -Werror

# define standard colors
BLACK		:= $(shell tput -Txterm setaf 0)
RED			:= $(shell tput -Txterm setaf 1)
GREEN		:= $(shell tput -Txterm setaf 2)
YELLOW		:= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	:= $(shell tput -Txterm setaf 4)
PURPLE		:= $(shell tput -Txterm setaf 5)
BLUE		:= $(shell tput -Txterm setaf 6)
WHITE		:= $(shell tput -Txterm setaf 7)
RESET		:= $(shell tput -Txterm sgr0)

#########################
# 		RULES			#
#########################

all: $(NAME)

$(NAME): $(OBJS) 
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo " Done!"

$(OBJS): %.o:%.c ${INCS} Makefile
	@echo " compiling: $<"
	@$(CC) $(CC_FLAGS) -I. -c $< -o $@

# clean commands
clean: print_clean
	@echo "remove all objects files"
	@rm -rf *.o

fclean: clean
	@echo "remove $(NAME)"
	@rm -rf $(NAME)

re: fclean all

# utility
norm:
	@echo "${LIGHTPURPLE}> Norminette Libft${RESET}"
	@norminette -R CheckDefine $(SRCS) $(SRCS_BONUS)

# print
print_clean:
	@echo "${RED}> Clean${RESET}"

.PHONY: all clean fclean re norm print_clean bonus
