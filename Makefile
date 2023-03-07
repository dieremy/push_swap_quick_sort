# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 10:37:31 by robegarc          #+#    #+#              #
#    Updated: 2023/03/01 12:20:23 by robegarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	srcs/push_swap.c srcs/push_swap_utils.c srcs/quick_sort.c srcs/in_out_check.c \
		operations/push.c operations/swap.c operations/reverse_rotate.c operations/rotate.c
OBJ = $(SRC:.c=.o)
CC = gcc -Wall -Wextra -Werror -g
NAME = push_swap
FT_PRINTF = ft_printf
LIBFT = libft
LIBRARY = ft_printf/libftprintf.a libft/libft.a

all	: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(FT_PRINTF)
	@make -C $(LIBFT)
	@$(CC) $(OBJ) $(LIBRARY) -o $(NAME)
	
clean :
	@make clean -C $(FT_PRINTF)
	@make clean -C $(LIBFT)
	@rm -f $(OBJ)
	
fclean : clean
	@make fclean -C $(FT_PRINTF)
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)
	
re : fclean clean all

.PHONY: clean fclean re all