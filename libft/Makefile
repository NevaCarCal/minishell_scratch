# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 18:50:10 by ncarrera          #+#    #+#              #
#    Updated: 2025/07/15 04:10:54 by ncarrera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags used at compile time
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Name of the library as specified in the rules of my project
NAME = libft.a

# Source files (We can't use wildcard since that is an easy way to have malicious\unknown code compiled along yours)
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
      ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
      ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
      ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
      ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
      ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
      ft_tolower.c ft_toupper.c ft_printf_m_helpers.c ft_print_hex.c \
      ft_printf.c gnl_utils.c gnl.c ft_hextoi.c ft_isspace.c ft_rgb.c \
      ft_free_str_array.c ft_error_handler.c ft_open.c ft_arrjoin.c \
      ft_arrlen.c ft_strjoin_tri.c ft_list_transform.c ft_list_parsing.c \
      ft_list_push.c ft_list_rot.c ft_list_swap.c ft_list_del.c ft_abs.c

# Object files (This variable holds a list of all the .o files, which have the same names as the regular .c ones)
OBJ = $(SRC:.c=.o)

# Header file's name, must be specified also explicitly
HEADER = libft.h

# Default rule to create the library (One of the mandatory rules)
all: $(NAME)

# Rule to create the static library from object files (Here we use the OBJ variable and create the actual .a file)
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

# Rule to compile each .c file into an object file
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

# Clean up object files and the library
fclean: clean
	@rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

# Rule to specify phony targets (so that make doesn't look for a file called 'clean', etc.)
.PHONY: all clean fclean re
