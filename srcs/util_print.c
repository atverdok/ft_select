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
	count_and_mov_elem(store);
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
	while (node)
	{
		count_and_mov_elem(store);
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
	store->index_cur = 0;
}
