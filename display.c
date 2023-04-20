#include <stdio.h>
#include "header.h"

void	print_dll_int(t_dll_node *cursor)
{
	int				data;

	while (cursor)
	{
		data = ((long long int)((*cursor).data));
		printf("Data = %d |prev = %p node = %p next = %p|\n", data, (*cursor).prev, cursor, (*cursor).next);
		cursor = (*cursor).next;
	}
}

void	print_dll_char(t_dll_node *cursor)
{
	char			data;

	while (cursor)
	{
		data = ((long long int)((*cursor).data));
		printf("Data = %c |prev = %p node = %p next = %p|\n", data,  (*cursor).prev, cursor, (*cursor).next);
		cursor = (*cursor).next;
	}
}

void	print_dll_double(t_dll_node *cursor)
{
	while (cursor)
	{
		printf("Data = %f |prev = %p node = %p next = %p|\n", *((double *)(*cursor).data),  (*cursor).prev, cursor, (*cursor).next);
		cursor = (*cursor).next;
	}
}

void	print_dll_string(t_dll_node *cursor)
{
	while (cursor)
	{
		printf("Data = %s |prev = %p node = %p next = %p|\n", (char*)((*cursor).data),  (*cursor).prev, cursor, (*cursor).next);
		cursor = (*cursor).next;
	}
}

