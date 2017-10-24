/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mode_terminal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:02:09 by atverdok          #+#    #+#             */
/*   Updated: 2017/06/21 15:02:12 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	reset_input_mode(t_main *main_struct)
{
	make_command("te");
	make_command("ve");
	tcsetattr(STDIN_FILENO, TCSANOW, &main_struct->saved_attributes);
}

void	save_attributes(t_main *main_struct)
{
	if (!isatty(STDIN_FILENO))
	{
		ft_putstr_fd("Not a terminal.\n", 2);
		exit(EXIT_FAILURE);
	}
	tcgetattr(STDIN_FILENO, &main_struct->saved_attributes);
}

void init_terminal_data(void)
{
	char *termtype;
	char term_buffer[1024];
	int success;

	termtype = getenv("TERM");
	if (termtype == 0)
	{
		ft_putstr_fd("Specify a terminal type with `setenv TERM <yourtype>'.\n",
					 2);
		exit(EXIT_FAILURE);
	}
	success = tgetent(term_buffer, termtype);
	if (success < 1)
	{
		if (success < 0)
			ft_putstr_fd("Could not access the termcap data base.\n", 2);
		else if (success == 0)
			ft_putstr_fd("Terminal type `%s' is not defined.\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	set_input_mode(void)
{
	struct termios tattr;

	init_terminal_data();
	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ICANON | ECHO);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
	make_command("os");
	make_command("vi");
	make_command("ti");
}
