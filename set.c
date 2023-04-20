#include <stdlib.h>
#include "header.h"

t_dll	*get_new_dll()
{
	t_dll	*dll = malloc(sizeof(t_dll));

	if (dll == NULL)
		return (NULL);
	(*dll).first = NULL;
	(*dll).cursor = NULL;
	(*dll).last = NULL;
	return (dll);
}

char	add_node_to_dll(t_dll *dll, void *data)
{
	t_dll_node	*node = NULL;

	if (dll == NULL)
		return (SUCCESS);
	node = malloc(sizeof(t_dll_node));
	if (node == NULL)
		return (FAIL);
	if ((*dll).first == NULL)
	{
		(*node).data = data;
		(*node).prev = NULL;
		(*node).next = NULL;
		(*dll).first = node;
		(*dll).last = node;
		(*dll).cursor = node;
		return (SUCCESS);
	}
	(*(*dll).cursor).next = node;
	(*node).data = data;
	(*node).prev = (*dll).cursor;
	(*node).next = NULL;
	(*dll).last = node;
	(*dll).cursor = node;
	return (SUCCESS);
}

char	insert_node_to_dll(t_dll *dll, void *data)
{
	t_dll_node	*node, *next;

	if (dll == NULL)
		return (SUCCESS);
	if ((*dll).first == NULL || (*dll).cursor == NULL)
		return (add_node_to_dll(dll, data));
	if ((*dll).cursor == (*dll).first && (*dll).cursor == (*dll).last)
		return (add_node_to_dll(dll, data));
	if ((*dll).cursor == (*dll).last)
	{
		node = malloc(sizeof(t_dll_node));
		if (node == NULL)
			return (FAIL);
		(*(*dll).cursor).next = node;
		(*node).prev = (*dll).cursor;
		(*node).next = NULL;
		(*node).data = data;
		(*dll).last = node;
		(*dll).cursor = node;
		return (SUCCESS);
	}
	node = malloc(sizeof(t_dll_node));
	if (node == NULL)
		return (FAIL);
	next = (*(*dll).cursor).next;
	(*(*dll).cursor).next = node;
	(*next).prev = node;
	(*node).next = next;
	(*node).prev = (*dll).cursor;
	(*node).data = data;
	(*dll).cursor = node;
	return (SUCCESS);
}

void	remove_node_to_dll(t_dll *dll)
{
	t_dll_node *prev, *next;

	if (dll == NULL)
		return ;
	if ((*dll).first == NULL || (*dll).cursor == NULL)
		return ;
	if ((*dll).cursor == (*dll).first && (*dll).cursor == (*dll).last)
	{
		if ((*dll).cursor)
			free((*dll).cursor);
		(*dll).cursor = NULL;
		(*dll).first = NULL;
		(*dll).last = NULL;
		return ;
	}
	if ((*dll).cursor == (*dll).first)
	{
		(*dll).first = (*(*dll).cursor).next;
		(*(*dll).first).prev = NULL;
		if ((*dll).cursor)
			free((*dll).cursor);
		(*dll).cursor = (*dll).first;
		return ;
	}
	if ((*dll).cursor == (*dll).last)
	{
		(*dll).last = (*(*dll).cursor).prev;
		(*(*dll).last).next = NULL;
		if ((*dll).cursor)
			free((*dll).cursor);
		(*dll).cursor = NULL;
		return ;
	}
	prev = (*(*dll).cursor).prev;
	next = (*(*dll).cursor).next;
	if ((*dll).cursor)
		free((*dll).cursor);
	(*prev).next = next;
	(*next).prev = prev;
	(*dll).cursor = next;
}

void	swap_node_to_dll(t_dll *dll, t_dll_node *node1, t_dll_node *node2)
{
	t_dll_node *n1_prev = (*node1).prev, *n2_prev = (*node2).prev, *n1_next = (*node1).next, *n2_next = (*node2).next;

	if (dll == NULL)
		return ;
	if ((*dll).first == (*dll).last)
		return ;
	if (node2 == n1_prev)
	{
		(*node1).prev = n2_prev;
		(*node1).next = node2;
		(*node2).prev = node1;
		(*node2).next = n1_next;
		if (n2_prev)
			(*n2_prev).next = node1;
		if (n1_next)
			(*n1_next).prev = node2;
	}
	else if(node2 == n1_next)
	{
		(*node1).prev = node2;
		(*node1).next = n2_next;
		(*node2).prev = n1_prev;
		(*node2).next = node1;
		if (n1_prev)
			(*n1_prev).next = node2;
		if (n2_next)
			(*n2_next).prev = node1;
	}
	else
	{
		(*node1).next = n2_next;
		(*node1).prev = n2_prev;
		(*node2).next = n1_next;
		(*node2).prev = n1_prev;
		if (n1_prev)
			(*n1_prev).next = node2;
		if (n1_next)
			(*n1_next).prev = node2;
		if (n2_prev)
			(*n2_prev).next = node1;
		if (n2_next)
			(*n2_next).prev = node1;
	}
	if (node1 == (*dll).first && node2 != (*dll).last)
	{
		(*dll).first = node2;
		return ;
	}
	if (node1 == (*dll).last && node2 != (*dll).first)
	{
		(*dll).last = node2;
		return ;
	}
	if (node2 == (*dll).first && node1 != (*dll).last)
	{
		(*dll).first = node1;
		return ;
	}
	if (node2 == (*dll).last && node1 != (*dll).first)
	{
		(*dll).last = node1;
		return ;
	}
	if (node1 == (*dll).first && node2 == (*dll).last)
	{
		(*dll).first = node2;
		(*dll).last = node1;
		return ;
	}
	if (node2 == (*dll).first && node1 == (*dll).last)
	{
		(*dll).first = node1;
		(*dll).last = node2;
		return ;
	}
}

void	destroy(t_dll *dll)
{
	if (dll == NULL)
		return ;
	t_dll_node *cursor = (*dll).first;

	while (cursor)
	{
		((*dll).cursor) = (*cursor).next;
		if (cursor)
			free(cursor);
		cursor = ((*dll).cursor);
	}
	if (dll)
		free(dll);
}
