NAME = push_swap
FILES = algorithm		\
			aux						\
			bigger_smaller\
			error_int			\
			error_str			\
			ft_atoi				\
			ft_lstlen			\
			ft_newnode		\
			ft_split			\
			ft_strchr			\
			ft_strlen			\
			ft_strncmp		\
			ft_substr			\
			moves_s				\
			push_swap			\
			ss_rr_rrr			\
			three_nbrs		\
			definitive		\
			last					\
			last_a				\

CC= gcc
CFLAGS= -Wall -Werror -Wextra -fsanitize=address -g3
RM= rm -rf
AR= ar rcs

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.a

all: $(NAME)

re: fclean all

.PHONY: all clean fclean re
