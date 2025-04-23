GREEN=\033[0;32m
NC=\033[0m

NAME     = so_long

CC       = cc
CFLAGS   = -Wall -Wextra -Werror
LMLX = -lmlx -framework OpenGL -framework AppKit

SRCSDIR      = ./srcs/
GNLDIR       = ../lib/get_next_line/
LIBFTDIR     = ../lib/libft/

LIBFT        = $(LIBFTDIR)libft.a

SRCS    =   $(GNLDIR)get_next_line_utils.c    \
            $(GNLDIR)get_next_line.c           \
            $(SRCSDIR)so_long_bonus.c 			\
			$(SRCSDIR)check_map_bonus.c 		 \
			$(SRCSDIR)get_map_bonus.c 			  \
			$(SRCSDIR)moves_bonus.c 			   \
			$(SRCSDIR)free_exit_bonus.c 		    \
			$(SRCSDIR)utils_bonus.c 				 \
			$(SRCSDIR)flood_fill_map_bonus.c 		  \
			$(SRCSDIR)animition_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LMLX) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)So_long Bonus compiled$(NC)"

%.o: %.c includes/so_long_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFTDIR)
	@rm -f $(OBJS)
	@echo "$(GREEN)Object files Bonus cleaned$(NC)"

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@rm -f $(NAME)
	@echo "$(GREEN)All Bonus cleaned$(NC)"

re: fclean all

.PHONY: clean