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
OBJ = $(SRC.o=.c)
NAME = push_swap

SRC_B =	srcs/checker.c
OBJ_B =	$(SRC_B.o=.c)
NAME_B = checker
#PSO = ${filter-out $(srcs/push_swap.o), ${OBJ}}

CC = gcc -Wall -Wextra -Werror -g
FT_PRINTF = ft_printf
LIBFT = libft
LIBRARY = ft_printf/libftprintf.a libft/libft.a

#all	: $(NAME) $(NAME_B)

#$(NAME) : $(OBJ)
#	@make -C $(FT_PRINTF)
#	@make -C $(LIBFT)
#	@$(CC) $(OBJ) $(LIBRARY) -o $(NAME)

#bonus : $(NAME) $(OBJ_B) $(OBJ)
#	@$(CC) $(OBJ_B) $(LIBRARY) -o $(NAME_B)

all :
	@make -C $(FT_PRINTF)
	@make -C $(LIBFT)
	@$(CC) $(SRC) $(LIBRARY) -o $(NAME)
	@$(CC) $(SRC_B) $(LIBRARY) -o $(NAME_B)

push_swap :
	@make -C $(FT_PRINTF)
	@make -C $(LIBFT)
	@$(CC) $(SRC) $(LIBRARY) -o $(NAME)

checker :
	@make -C $(FT_PRINTF)
	@make -C $(LIBFT)
	@$(CC) $(SRC_B) $(LIBRARY) -o $(NAME_B)

clean :
	@make clean -C $(FT_PRINTF)
	@make clean -C $(LIBFT)
	@rm -f $(OBJ)
	@rm -f $(OBJ_B)
	
fclean : clean
	@make fclean -C $(FT_PRINTF)
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	
re : fclean clean all bonus

.PHONY: clean fclean re all bonus