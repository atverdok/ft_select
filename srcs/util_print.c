//
// Created by Aleksey Tverdokhleb on 10/25/17.
//

#include "../includes/ft_select.h"

void	print_selected(t_arg_node *node)
{
	make_command("us");
	if (node->select)
		print_inverted(node->value);
	else
		ft_putstr(node->value);
	make_command("ue");
}

void	unset_mark()
{
	t_main *store;

	store = store_t_main_struct(NULL);
	mov_elem(store, store->index_cur);
	if (store->curr->select)
		print_inverted(store->curr->value);
	else
		ft_putstr(store->curr->value);
}

void	print_inverted(char *name)
{
	make_command("so");
	ft_putstr(name);
	make_command("se");
}

void	make_str(void)
{
	t_main *store;
	t_arg_node *node;
	int i;

	store = store_t_main_struct(NULL);
	node = store->head;
	i = 0;
	if (is_space())
	{
		while (node)
		{			
			mov_elem(store, i);
			count_shift(1);
			if (store->under == i)
				print_selected(node);
			else if (node->select)
				print_inverted(node->value);
			else
				ft_putstr(node->value);
			node = node->next;
			i++;
		}
	}
	else
		ft_putstr("NO SPACE");
}

int	is_space(void)
{
	t_main *store;

	store = store_t_main_struct(NULL);
	get_term_size(store);
	max_last_len();
	make_tgoto("cm", 0, 0);
	make_command("cl");
	if ((store->last_len + count_col(store->total_nodes - 1)) <= store->co)
		return (1);
	return (0);
}
