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

t_arg_node	*get_index(t_arg_node *list, int old_index, int new_index)
{
	t_arg_node *tmp;

	tmp = list;
	while (old_index != new_index)
	{
		if (old_index < new_index)
		{
			tmp = tmp->next;
			old_index++;
		}
		else if (old_index > new_index)
		{
			tmp = tmp->prew;
			old_index--;
		}
	}
	return (tmp);
}

t_main		*init_main_struct(void)
{
	t_main *tmp;

	tmp = ft_memalloc(sizeof(t_main));
	return (tmp);
}

void		del_node(t_arg_node **delete)
{
	ft_strdel(&(*delete)->value);
	ft_memdel((void *)delete);
}