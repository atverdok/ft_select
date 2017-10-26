
#include "../includes/ft_select.h"

void	del_quote(char **str)
{
	char *begin;

	begin = *str;
	while (*begin != '\0')
	{
		if (*begin == '\'' || *begin == '"')
		{
			ft_memmove(begin, (begin + 1), ft_strlen(begin));
			continue ;
		}
		begin++;
	}
}

t_main		*store_t_main_struct(t_main *main_struct)
{
	static t_main *store = NULL;

	if (store == NULL && main_struct)
		store = main_struct;
	return (store);
}

t_arg_node *parse_arg(int argc, char **argv)
{
	int i;
	char **arg;
	t_arg_node *args;

	args = NULL;
	i = 0;
	while (++i < argc)
	{
		del_quote(&argv[i]);
		arg = ft_strsplit(argv[i], ' ');
		while (*arg != NULL)
		{
			push_list(&args, *arg);
			arg++;
		}
	}
	return (args);
}

void	set_terminal(t_main *main_struct)
{
	set_input_mode();
}

void	make_select(t_main *main_struct)
{
	char buf[8];

//	print_list(main_struct);
	make_str();
	ft_bzero(buf, 8);
	while (read(STDIN_FILENO, buf, 8))
	{
		if (!ft_strcmp(buf, KEY_DOWN))
			move_down();
		else if (!ft_strcmp(buf, KEY_UP))
			move_up();
		else if (!ft_strcmp(buf, KEY_LEFT))
			move_left();
		else if (!ft_strcmp(buf, KEY_RIGHT))
			move_right();
		else if (!ft_strcmp(buf, KEY_BACKSPACE) || !ft_strcmp(buf, KEY_DELETE))
			del_elem();
		else if (!ft_strcmp(buf, KEY_SPACE))
		{
			select_elem();
			move_down();
		}
		else if (!ft_strcmp(buf, KEY_ESC))
			break ;
		ft_bzero(buf, 8);
	}
}

int     main(int argc, char **argv)
{
	t_arg_node *args;
	t_main *main_struct;

	if (argc < 2)
		// show usage
		;
	else
	{
		args = parse_arg(argc, argv);
		main_struct = store_t_main_struct(init_main_struct());
		main_struct->head = args;
		main_struct->curr = main_struct->head;
		save_attributes(main_struct);
		set_terminal(main_struct);
		main_struct->total_nodes++;
		while (args->next)
		{
			main_struct->total_nodes++;
			if (ft_strlen(args->value) > main_struct->max_len)
				main_struct->max_len = ft_strlen(args->value);
			args = args->next;
		}
		main_struct->shift = 1;
		main_struct->tail = args;
		get_term_size(main_struct);
        make_select(main_struct);
        reset_input_mode(main_struct);
	}
	return (0);
}