//
// Created by Aleksey Tverdokhleb on 10/26/17.
//

#include "../includes/ft_select.h"

int 		we(void)
{
	t_main *store;
	int		col;

	store = store_t_main_struct(NULL);
	col = (int)(store->co / (store->max_len + store->shift));

}

void		handler(int sig)
{
	t_main *store;

	store = store_t_main_struct(NULL);
//	if (sig == SIGTSTP)
//		pause_process();
//	else if (sig == SIGCONT)
//		restore_process();
//	else if (sig == SIGTERM || sig == SIGABRT || sig == SIGINT ||
//			 sig == SIGSTOP || sig == SIGKILL || sig == SIGQUIT)
//		exit_program();
//	else
	if (sig == SIGWINCH)
	{

		get_term_size(store);
		max_last_len();
		make_tgoto("cm", 0, 0);
		make_command("cl");

		if ((store->last_len + count_col(store->total_nodes - 1)) < store->co)
			make_str();
		else
			ft_putstr("NO SPACE");
	}
}

void		catch_signals(void)
{
	signal(SIGWINCH, handler);
	signal(SIGTERM, handler);
	signal(SIGABRT, handler);
	signal(SIGINT, handler);
	signal(SIGSTOP, handler);
	signal(SIGCONT, handler);
	signal(SIGTSTP, handler);
	signal(SIGKILL, handler);
	signal(SIGQUIT, handler);
}