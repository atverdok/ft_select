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

pid_t	g_pid;
struct termios	g_saved_attributes;

typedef struct s_in_arg
{
    int             select;
    char            *value;
    struct s_in_arg *next;
    struct s_in_arg *prew;
}              t_in_arg;

void	reset_input_mode(void);
void	save_attributes(void);
void	set_input_mode(void);

#endif
