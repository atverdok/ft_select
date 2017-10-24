
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

void	print_list(t_main *main_struct, int key)
{
	t_arg_node *list;

	list = main_struct->head;
	while (list)
	{
        if (!key)
            ft_putendl(list->value);
        else if (key && list->select)
            ft_putendl(list->value);    
		list = list->next;
	}
}

void	make_select(t_main *main_struct)
{
	char buf[8];

	print_list(main_struct, 0);
	while (read(STDIN_FILENO, buf, 8))
	{
//		if (buf[0] == 27 && buf[1] == 0)
		if ((buf[0] + buf[1] + buf[2] + buf[3] + buf[4]) == KEY_ESC)
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
		main_struct = ft_memalloc(sizeof(t_main));
		main_struct->head = args;
		save_attributes(main_struct);
		set_terminal(main_struct);
		while (args->next)
		{
			if (ft_strlen(args->value) > main_struct->max_len)
				main_struct->max_len = ft_strlen(args->value);
			args = args->next;
		}
		main_struct->tail = args;
		get_term_size(main_struct);
        make_select(main_struct);
        reset_input_mode(main_struct);
        print_list(main_struct, 1);
	}
	return (0);
}