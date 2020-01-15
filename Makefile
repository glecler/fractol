NAME 	= fractol
SRC 	= ./srcs/utilitaries.c ./srcs/img_draw.c ./srcs/complex.c \
			./srcs/algo.c ./srcs/main.c ./srcs/key_handler.c \
			./srcs/user_interface.c
FLAGS 	= -Wall -Wextra -Werror 
CC		= gcc
	CL=\x1b[35m
	GREEN=\033[1;32m
	RED=\033[1;31m
	CL2=\x1b[36m
	NC=\033[0m

all: $(NAME)

$(NAME): $(SRC)
	@$(MAKE) -C libft
	@$(CC) $(FLAGS) -lpthread -I minilibx_macos $(SRC) ./libft/libft.a -L minilibx_macos -lmlx -framework OpenGL -framework Appkit -o fractol
	@echo "$(GREEN)[✓]$(NC)$(CL) $(NAME) built$(NC)"

clean:
	@rm -rf $(OBJ)
	@cd libft && $(MAKE) clean
	@echo "$(RED)[-]$(NC)$(CL2) Objects of $(NAME) cleaned$(NC)"

fclean: clean
	@cd libft && $(MAKE) fclean
	@rm -rf fractol
	@echo "$(RED)[-]$(NC)$(CL2) fractol cleaned$(NC)"

re: fclean all

.PHONY: test, all, $(NAME), clean, fclean, re
