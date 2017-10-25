//
// Created by Aleksey Tverdokhleb on 10/24/17.
//

#include "../includes/ft_select.h"

t_arg_node	*create_node(void)
{
	t_arg_node *tmp;

	tmp = (t_arg_node *)ft_memalloc(sizeof(t_arg_node));
	return (tmp);
}

void		push_list(t_arg_node **list, char *value)
{
	t_arg_node *new_node;
	t_arg_node *head;

	new_node = create_node();
	new_node->value = value;
	if (*list == NULL)
		*list = new_node;
	else
	{
		head = *list;
		while ((*list)->next)
			(*list) = (*list)->next;
		new_node->prew = *list;
		(*list)->next = new_node;
		*list = head;
	}
}

t_arg_node	*get_index(t_arg_node *list, int index)
{
	t_arg_node *tmp;

	if (index < list->index && index >= 0)
	{
		while (list->prew && list->index != index)
			list = list->prew;
	}
	else if (index > list->index && list->next)
	{
		while (list->prew && list->index != index)
			list = list->next;
	}
	tmp = list;
	return (tmp);
}

t_main		*init_main_struct(void)
{
	t_main *tmp;

	tmp = ft_memalloc(sizeof(t_main));
	return (tmp);
}