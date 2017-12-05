//
// Created by Aleksey Tverdokhleb on 10/26/17.
//

#include "../includes/ft_select.h"

void	reshuffle_link(t_main *main)
{
	t_arg_node *next;
	t_arg_node *prew;

	next = main->curr->next;
	prew = main->curr->prew;

	if (next)
		next->prew = prew;
	if (prew)
		prew->next = next;

	del_node(&main->curr);
	main->total_nodes--;
	if (next)
		main->curr = next;
	else
		main->curr = main->head;
}

void	del_elem(void)
{
	t_main *store;
	int tmp_index;

	store = store_t_main_struct(NULL);
	if (store->curr->prew == NULL)
		store->head = store->curr->next;
	if (store->curr->next == NULL)
		store->tail = store->curr->prew;
	reshuffle_link(store);
	tmp_index = (store->index_cur < store->total_nodes) ? store->index_cur : 0;
	store->under = tmp_index;
	store->index_cur = 0;
	make_command("cl");
	make_str();
	if (tmp_index < store->total_nodes)
		store->index_cur = tmp_index;
	if (!store->total_nodes)
	{
		reset_input_mode();
		exit(0);
	}
}

