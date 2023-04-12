#include <stdio.h>
#include "header.h"

void	print_dll_int(t_dll_node *cursor)
{
	int				data;
	long long int	mask = 0xFFFFFFFFFFFFFFF;

	while (cursor)
	{
		data = (int)((long long int)((*cursor).data) & mask);
		printf("Data = %d |prev = %p node = %p next = %p|\n", data, (*cursor).prev, cursor, (*cursor).next);
		cursor = (*cursor).next;
	}
}

void	print_dll_char(t_dll_node *cursor)
{
	char			data;
	long long int	mask = 0xFFFFFFFFFFFFFFF;

	while (cursor)
	{
		data = (char)((long long int)((*cursor).data) & mask);
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

