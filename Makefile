GREEN=\033[0;32m
NC=\033[0m

NAME     = so_long

CC       = cc
CFLAGS   = -Wall -Wextra -Werror
LMLX = -lmlx -framework OpenGL -framework AppKit

SRCSDIR      = ./srcs/
GNLDIR       = ./lib/get_next_line/
LIBFTDIR     = ./lib/libft/

LIBFT        = $(LIBFTDIR)libft.a

SRCS    =   $(GNLDIR)get_next_line_utils.c    \
            $(GNLDIR)get_next_line.c          \
            $(SRCSDIR)so_long.c \
			$(SRCSDIR)check_map.c \
			$(SRCSDIR)get_map.c \
			$(SRCSDIR)moves.c \
			$(SRCSDIR)free_exit.c \
			$(SRCSDIR)utils.c \
			$(SRCSDIR)flood_fill_map.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus:
	@make -C bonus

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LMLX) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)So_long compiled$(NC)"

%.o: %.c includes/so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C bonus
	@make clean -C $(LIBFTDIR)
	@rm -f $(OBJS)
	@echo "$(GREEN)Object files cleaned$(NC)"

fclean: clean
	@make fclean -C bonus
	@make fclean -C $(LIBFTDIR)
	@rm -f $(NAME)
	@echo "$(GREEN)All cleaned$(NC)"

re: fclean all

.PHONY: clean bonus