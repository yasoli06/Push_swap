#COLORS#
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m
YELLOW= \033[1;33m

NAME = push_swap

SRC = main.c utils.c push_swap.c movements.c radix.c utils_libft.c

OBJ = $(SRC:%.c=%.o)

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

%.o: %.c Makefile push_swap.h
	$(CC) -c $< $(CFLAGS) -o $@
	@echo "$(YELLOW)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)PUSH_SWAP DONE$(END)"

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)OBJECTS DELETED$(END)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)OBJECTS2 DELETED$(END)"

re: fclean all

.PHONY: all clean fclean re