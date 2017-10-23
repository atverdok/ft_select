//
// Created by atverdok on 10/23/17.
//

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termcap.h>
# include <sys/ioctl.h>
# include <termios.h>

# include "../libft/libft.h"

pid_t	g_pid;
struct termios	g_saved_attributes;

#endif
