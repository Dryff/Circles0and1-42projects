NAME		=	fdf
HEADER		=	fdf.h 

SRCS		= 	fdf.c parsing_color.c fdf_utils.c ft_split_to_int.c drawing.c drawing_utils.c\
				GNL/get_next_line.c GNL/get_next_line_utils.c \
				ft_err_printf/ft_print_hexa.c ft_err_printf/ft_printf.c ft_err_printf/ft_putnbr_u.c ft_err_printf/ft_putnbr.c ft_err_printf/ft_putstr_int.c 

MLX			=	mlx/libmlx
				
OBJS		:= $(SRCS:%.c=%.o)

CC			=	cc
FLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME): 	compilemlx print $(OBJS)
			$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
			@echo "\033[35m Project successfully compiled"

$(OBJS): 	%.o:%.c ${HEADER}
			@echo "\033[36m compiling: $<"
			@$(CC) $(FLAGS) -Imlx -c $< -o $@

compilemlx :
			$(MAKE) -C mlx

print:		
			@echo "\033[31m ~ Compiling fdf ~"

clean:
	@echo "\033[31m > Removed all objects files <"
	@rm -rf *.o mlx/*.o ft_err_printf/*.o GNL/*.o

fclean: clean
	@echo "\033[31m * Removed $(NAME) *"	
	@rm -rf $(NAME) mlx/libmlx.a

re: fclean all

.PHONY:		all clean fclean re