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

//pid_t	g_pid;
//struct termios	g_saved_attributes;

// buf[0] + buf[1] + buf[2] + buf[3] + buf[4]

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
	struct termios	cur_attributes;
	t_arg_node		*head;
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

/*
** util_termcap.c
*/
int 		make_command(char *command);
int 		get_term_size(t_main *main_struct);

#endif
