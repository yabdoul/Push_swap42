CC = cc

CFLAGS =  -Wall -Werror -Wextra 

NAME = push_swap

SRC	=  push_swap.c parsing.c ft_split.c sort_algo.c sort_tools.c utils.c arg_validations.c push.c 
			 

OBJS = ${SRC:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) $(OBJS)  -o $(NAME) 
  
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all