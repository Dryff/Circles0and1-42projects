NAME		=	pipex
HEADER		=	pipex.h

SRCS		= 	pipex.c ft_split.c pipex_utils.c error_management.c

OBJS		:= $(SRCS:%.c=%.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	print $(OBJS) compile
			@echo "\033[31m > Done!"

compile:	
			@gcc -o pipex ft_split.o pipex.o pipex_utils.o error_management.o

$(OBJS): %.o:%.c ${HEADER} Makefile
			@echo "\033[36m compiling: $<"
			@$(CC) $(CC_FLAGS) -c $< -o $@

print:		
			@echo "\033[31m ~ Compiling pipex ~"

clean:
	@echo "\033[31m > Removed all objects files <"
	@rm -rf *.o

fclean: clean
	@echo "\033[31m * Removed $(HEADER) *"	
	@rm -rf $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus