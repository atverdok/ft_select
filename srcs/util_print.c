//
// Created by Aleksey Tverdokhleb on 10/25/17.
//

#include "../includes/ft_select.h"

void	print_selected(t_arg_node *node)
{
	ft_putstr("\e[4m");
	if (node->select)
	{
		ft_putstr("\e[7m");
		ft_putstr(node->value);
		ft_putstr("\e[27m");
	} else
		ft_putstr(node->value);
	ft_putstr("\e[24m");
}

void	unset_mark()
{
	t_main *store;

	store = store_t_main_struct(NULL);
		make_tgoto("cm", (store->index_cur / store->li),
				   (store->index_cur % store->li));
	if (store->curr->select)
		print_inverted(store->curr->value);
	else
		ft_putstr(store->curr->value);
}

void	print_inverted(char *name)
{
	ft_putstr("\e[7m");
	ft_putstr(name);
	ft_putstr("\e[27m");
}

void	make_str(void)
{
	t_main *store;
	int col;
	int row;
	int fill = 1;
	char **out;

	store = store_t_main_struct(NULL);

	col = (int)(store->co / (store->max_len + fill));
	row = (store->total_nodes / col) + (store->total_nodes % col);
	out = (char **)ft_memalloc(sizeof(char *) * row);

	int i = -1;
	while (++i < row)
	{
		out[i] = (char *)malloc(sizeof(char) * ((store->max_len * col) + (col * fill - 1)));
		ft_memset(out[i], ' ', (store->max_len * col));
		out[i][((store->max_len * col) + (col * fill - 1))] = '\0';
	}
	i = -1;

	t_arg_node *node;
	int j = 0;
	node = store->head;
	while (++i < row && node)
	{
		ft_memcpy((out[i] + ((store->max_len + fill) * j)), node->value, ft_strlen(node->value));
		if (i == (row - 1) && (j < col))
		{
			j++;
			i = -1;
		}
		node = node->next;
	}
	i = -1;
	while (++i < row)
		ft_putendl(out[i]);
}

void	print_list(t_main *main_struct)
{
	make_str();

//	t_arg_node *list;
//
//	list = main_struct->head;
//	while (list)
//	{
//		if (list->prew == NULL)
//		{
//			print_selected(list);
//			ft_putchar('\n');
//		}
//		else
//			ft_putendl(list->value);
//		list = list->next;
//	}
}
