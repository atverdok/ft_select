//
// Created by Aleksey Tverdokhleb on 10/26/17.
//

#include <signal.h>
#include "../includes/ft_select.h"

void		handler(int sig)
{
	if (sig == SIGWINCH)
		make_str();
	else if (sig == SIGTSTP)
	{
		reset_input_mode();
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	}
	else if (sig == SIGCONT)
	{
		set_input_mode();
		make_str();
	}
}

void		catch_signals(void)
{
	signal(SIGWINCH, handler);
}

void	registr_signal_handl(void)
{
 	struct sigaction act;

	memset(&act, 0, sizeof(act));

	act.sa_handler = handler;
	sigaction(SIGWINCH, &act, NULL);
	sigaction(SIGTSTP, &act, NULL);
	sigaction(SIGCONT, &act, NULL);
}