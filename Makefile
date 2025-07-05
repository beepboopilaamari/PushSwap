# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilaamari <ilaamari@42nice.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 20:36:42 by ilaamari          #+#    #+#              #
#    Updated: 2025/07/05 20:36:42 by ilaamari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = main.c \
       sorting.c \
       parsing/parsing.c \
       parsing/input_check.c \
       operations/swap.c \
       operations/push.c \
       operations/rotate.c \
       operations/reverse.c \
       algorithm/turkish_sort.c \
       algorithm/sort_three.c \
       algorithm/cost.c \
       algorithm/position.c \
       algorithm/do_mv.c \
       utils/stack_utils.c \
       utils/utils.c \
       utils/string_utils.c \
       utils/ft_split.c

SRCS_PATH = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re