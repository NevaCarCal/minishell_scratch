# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/14 13:41:25 by ncarrera          #+#    #+#              #
#    Updated: 2026/03/16 13:51:26 by ncarrera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program requirements and settings as per the spec
NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./headers

# Linker flags eg. for readline
LDFLAGS = -lreadline -L./libft -lft

# Libft and project declarations
LIBFT = ./libft/libft.a
SRCS =	./src/main.c ./src/token_handler.c
		./src/commands/cmd_parsing.c ./src/commands/cmd_execution.c
		./src/shell/shell_loop.c

OBJS = $(SRCS:.c=.o)

# Colours
NC=\033[0m
Purple=\033[0;35m
Cyan=\033[1;36m
Red=\033[0;31m
LC=\033[2K

# Make rules and PHONY declarations
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	@make -C libft -s

%.o: %.c
	@printf "$(Cyan)Compiling: $(Purple)$<$(NC)\n"
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@printf "$(Red)Deleting: $(Purple)$(OBJS)$(NC)\n"
	@rm -f $(OBJS)
	@make clean -C libft -s

fclean: clean
	@printf "$(Red)Deleting: $(Purple)$(NAME)$(NC)\n"
	@rm -f $(NAME)
	@make fclean -C libft -s
re: fclean all
reclean:
	@$(MAKE) re -s
	@$(MAKE) clean -s

.PHONY: all clean fclean re reclean
