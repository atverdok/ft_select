//
// Created by Aleksey Tverdokhleb on 10/24/17.
//
#include "../includes/ft_select.h"

static int tcap_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int 		make_command(char *command)
{
	char	*tmp;
	if ((tmp = tgetstr(command, NULL)) == NULL)
		return (1);
	tputs(tmp, 0, tcap_putchar);
	return (0);
}

int 		get_term_size(t_main *main_struct)
{
	init_terminal_data();
	if (main_struct->co != tgetnum("co") || main_struct->li != tgetnum("li"))
	{
		main_struct->co = tgetnum("co");
		main_struct->li = tgetnum("li");
		return (1);
	}
	return (0);
}

t_main
