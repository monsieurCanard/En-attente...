
################
##  COMPILE	  ##
################


CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

#################
##   INCLUDE   ##
#################

INCLUDE_LIST	=	./includes/

INCLUDE			=	$(addprefix -I, $(INCLUDE_LIST))


#################
##   SOURCES   ##
#################

SRC_DIR				=	sources/

SRC_UTILS_DIR		=	utils/

SRC_UTILS_LIST		=	ft_atoi.c \
						get_time_of_the_day.c \
						print_info.c \
						verif_arg.c \
						verif_dead.c \
						pocket_philo.c
SRC_UTILS			=	$(addprefix $(SRC_UTILS_DIR), $(SRC_UTILS_LIST))

SRC_LIST			=	free.c	\
						init_data.c	\
						init_mutex_forks.c	\
						init_mutex_ressource.c	\
						init_permission_fork.c	\
						init_thread.c	\
						main.c	\
						monitor.c	\
						philo.c	\
						routine_utils.c	\
						routine.c	\
						waiting_end.c\
						$(SRC_UTILS) 
SRC					=	$(addprefix $(SRC_DIR), $(SRC_LIST))

##################
##   OBJ/NAME   ##
##################

NAME		=	philo

OBJ_DIR		=	objects/
OBJ_LIST	=	$(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

#################
##	 COLORS	   ##
#################

COLOR_RESET		=	\033[0m
COLOR_GREEN		=	\033[32m
COLOR_RED		=	\033[31m
COLOR_BLUE		=	\033[34m

#################
##    RULES    ##
#################



all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_UTILS_DIR)


$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJ_DIR)
	@echo "$(COLOR_BLUE)Compile $<$(COLOR_RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -c $< -o $@

$(NAME): $(OBJ_LIST) 
	@echo "$(COLOR_BLUE)Compile $(NAME)$(COLOR_RESET)"
	@$(CC) $(CFLAGS) $(OBJ_LIST) -o $(NAME)

clean:
	@echo "$(COLOR_RED)Delete objects$(COLOR_RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(COLOR_RED)Delete $(NAME)$(COLOR_RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re