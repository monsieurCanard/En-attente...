
NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=thread -g3 

GREEN        := \033[0;92m
YELLOW        := \033[0;93m
BLUE        := \033[0;94m
END_COLOR    := \033[0;39m

#Les différents fichiers à compiler
INC 		= 	push_swap.h

SRCS 		= 	init_data.c \
				main.c \
				init_thread.c \
				init_mutex_forks.c \
				ft_atoi.c \
				get_time_of_the_day.c \
				monitor.c \
				print_info.c \
				routine.c \
				free.c \
				init_mutex_ressource.c \
				verif_dead.c


#Declarer Objet avec le groupe  
OBJSOURCE = $(SRCS:.c=.o)
OBJS = $(addprefix obj/, $(OBJSOURCE))
#Création l'éxécutable 
$(NAME): ${OBJS}
		@${CC} ${CFLAGS} $(OBJS) -o $(NAME)
		@echo "$(GREEN)Compiled $(NAME):)$(END_COLOR)"


all: $(NAME)

obj/%.o: %.c
		@mkdir -p obj
		@$(CC) $(CFLAGS) -c -o $@ $<
		@echo "$(BLUE)Compiled $<$(END_COLOR)"

#Regle de nettoyage des fichiers objets 
clean:	
		@rm -rf obj
		@echo "$(YELLOW)Removed object files.$(END_COLOR)"

#Regle de nettoyage executable
fclean:	clean
		@rm -f $(NAME) 
		@echo "$(YELLOW)Cleaned libraries and $(NAME) executable.$(END_COLOR)"


re:	fclean all 
	@echo "$(GREEN)Cleaned all and rebuilt $(NAME)$(END_COLOR)"


#Eviter que meme si un fichier s'appelle clean, make executera la règle.
.PHONY: re clean fclean bonus
