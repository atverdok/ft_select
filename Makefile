
NAME	= ft_select

NAME_D	= ft_select_deb

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

CFLAGS_D = -g 

INCLUDES = includes/

LIBFTDIR = libft/

SRCS	= del_node.c main.c move_elem.c util_linkedlist.c util_mode_terminal.c util_print.c util_signals.c util_termcap.c

OBJ = $(SRCS:.c=.o)

OBJ_D = $(SRCS:.c=_D.o)

all: $(NAME)

debug : $(NAME_D)

$(NAME) : $(OBJ) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFTDIR) -lft -ltermcap

$(NAME_D) : $(OBJ_D) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS_D) $(OBJ_D) -o $(NAME_D) -L./$(LIBFTDIR) -lft -ltermcap

%.o: srcs/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

%_D.o: srcs/%.c $(INCLUDES)
	$(CC) $(CFLAGS_D) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)	

$(LIBFTDIR)libft.a: $(LIBFTDIR)Makefile
	make -C $(LIBFTDIR)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_D)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_D)

re: clean all	