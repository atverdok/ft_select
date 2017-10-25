//
// Created by atverdok on 10/23/17.
//

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <stdio.h>

# include <termcap.h>
# include <sys/ioctl.h>
# include <termios.h>

# include "../libft/libft.h"
# include "./defines.h"

typedef struct s_in_arg
{
    int             select;
    int             index;
    char            *value;
    struct s_in_arg *next;
    struct s_in_arg *prew;
}              t_arg_node;

typedef struct s_main
{
	int 			co;
	int 			li;
	int 			total_nodes;
	int 			index_cur;
	size_t			max_len;
	struct termios	saved_attributes;
	t_arg_node		*head;
	t_arg_node		*curr;
	t_arg_node		*tail;
}				t_main;

/*
** util_mode_terminal.c
*/
void	reset_input_mode(t_main *main_struct);
void	save_attributes(t_main *main_struct);
void	set_input_mode(void);
void	init_terminal_data(void);

/*
** util_linkedlist.c
*/
void		push_list(t_arg_node **list, char *value);
t_arg_node	*get_index(t_arg_node *list, int index);
t_main		*init_main_struct(void);

/*
** util_termcap.c
*/
int 		get_term_size(t_main *main_struct);
int 		make_command(char *command);
int 		make_tgoto(char *command, int co, int li);

/*
** main.c
*/
t_main		*store_t_main_struct(t_main *main_struct);

/*
** util_print.c
*/
void	unset_mark();
void	print_selected(t_arg_node *node);
void	print_inverted(char *name);
void	print_list(t_main *main_struct);

/*
** move_elem.c
*/
void	move_down(void);
void	move_up(void);
void	select_elem(void);

#endif
