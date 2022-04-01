NAME	=	push_swap

NAME_B	=	checker

SRCS	=	srcs/push_swap.c				srcs/data_initialisation.c		srcs/parsing_and_validation.c\
			srcs/stack_base_operations.c	srcs/median_operations.c			srcs/small_group_sorting.c\
			srcs/big_group_sorting.c		srcs/big_group_second_sorting.c	cmd/pa_pb.c\
			cmd/ra_rb.c						cmd/rra_rrb.c					cmd/sa_sb.c

SRCS_B	=	srcs/checker.c					srcs/data_initialisation.c		srcs/parsing_and_validation.c\
            srcs/stack_base_operations.c	srcs/medan_operations.c			srcs/small_group_sorting.c\
            srcs/big_group_sorting.c		srcs/big_group_second_sorting.c	srcs/checker_utils.c\
            cmd/pa_pb.c			            cmd/ra_rb.c						cmd/rra_rrb.c\
            cmd/sa_sb.c

OBJ		=	$(SRCS:%.c=%.o)

OBJ_B	=	$(SRCS_B:%.c=%.o)

LIB		=	libft/libft.a

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra

RM		= 	rm -rf

.PHONY:		all clean	fclean	re	bonus

all:		$(NAME)

$(NAME):	$(OBJ)
			@echo "Compilation of $(NAME)"
			@$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
			@echo "\n[ Finished $(NAME) ] \n"

%.o:		%.c
			@$(CC) $(FLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) -s -C
			@echo "\n[ Cleaning finished ]\n"

fclean:		clean
			@$(MAKE) -s -C
			@$(RM) $(NAME) $(NAME_B)
			@echo "\n[ Fcleaning finished ]\n"

re:			fclean all
			@echo "\n[ Remake done ]\n"

#bonus:		$(OBJ_B)