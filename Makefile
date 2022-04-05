NAME	=	push_swap

NAME_B	=	checker

SRCS	=	srcs/push_swap.c				srcs/data_initialisation.c 		srcs/parsing_and_validation.c\
			srcs/stack_base_operations.c 	srcs/median_operations.c 		cmd/pa_pb.c\
			cmd/ra_rb.c						cmd/rra_rrb.c					srcs/small_group_sorting.c\
			cmd/sa_sb.c						srcs/big_group_sorting.c		srcs/big_group_second_sorting.c

SRCS_B	=	srcs/checker.c					srcs/parsing_and_validation.c	srcs/data_initialisation.c\
			srcs/stack_base_operations.c	cmd/pa_pb.c						cmd/sa_sb.c\
			cmd/ra_rb.c						cmd/rra_rrb.c					srcs/median_operations.c\
			srcs/small_group_sorting.c		srcs/big_group_sorting.c		srcs/big_group_second_sorting.c\
			srcs/checker_utils.c


OBJ		=	$(SRCS:%.c=%.o)

OBJ_B	=	$(SRCS_B:%.c=%.o)

LIB		=	lib/libft.a

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf

.PHONY:		all	clean	fclean	re	bonus

all:		$(NAME)

$(NAME):	$(OBJ)
			@echo "[ $(NAME) compilation ]"
			@$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
			@echo "\n[ $(NAME) compiled ] \n"

%.o:		%.c
			@$(CC) $(FLAGS)  -c $< -o $@

bonus:		$(OBJ_B)
			@$(CC) $(FLAGS) $(OBJ_B) $(LIB) -o $(NAME_B)
			@echo "\n[ Bonus part compiled! ]\n"

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@echo "\n[ Cleaning done ]\n"

fclean:		clean
			@$(RM) $(NAME) $(NAME_B)
			@echo "\n[ Deleting done! ]\n"

re:			fclean all
			@echo "[ Remake finished ]\n"


