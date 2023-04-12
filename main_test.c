#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*quick test of the library's functions*/
int	main(void)
{
	t_dll		*dll = NULL;
	int			i = -1, nb_node = 10;
	char		data = 48;
	char		*string = "abdc def", *string0 = "1 2 3 4_5_6_7_8_9", *string1 = "nbvcxw";

///////////////////////////////////////////////////////////////////////////////
//###################
//########INT########
//###################
//creation of dll
	printf("\tINT:\n");
	dll = get_new_dll();
	if (dll == NULL)
		return (ERROR);
//addition of nodes and data
	while (++i < nb_node)
		if (add_node_to_dll(dll, to_void(i)) == FAIL)
		{
			destroy(dll);
			return (ERROR);
		}
//display all nodes
	print_dll_int((*dll).first);
	putchar('\n');

//insert
	printf("\t\tinsert:\n");
	i = -1;
	(*dll).cursor = (*dll).first;
	insert_node_to_dll(dll, to_void(-1));//first
	while (++i < 5)
		(*dll).cursor = (*(*dll).cursor).next;
	insert_node_to_dll(dll, to_void(50));//mid
	while ((*(*dll).cursor).next)
		(*dll).cursor = (*(*dll).cursor).next;
	insert_node_to_dll(dll, to_void(100));//last
	print_dll_int((*dll).first);
//remove
	printf("\t\tremove:\n");
	i = -1;
	(*dll).cursor = (*dll).first;
	remove_node_to_dll(dll);//first
	while (++i < 6)
		(*dll).cursor = (*(*dll).cursor).next;
	remove_node_to_dll(dll);//mid
	while ((*(*dll).cursor).next)
		(*dll).cursor = (*(*dll).cursor).next;
	remove_node_to_dll(dll);//last
	print_dll_int((*dll).first);
//swap
	printf("\t\tswap first / last:\n");
	swap_node_to_dll(dll, (*dll).first, (*dll).last);
	print_dll_int((*dll).first);
	printf("\t\tswap last / first:\n");
	swap_node_to_dll(dll, (*dll).last, (*dll).first);
	print_dll_int((*dll).first);
	printf("\t\tswap last / prev:\n");
	swap_node_to_dll(dll, (*dll).last, (*(*dll).last).prev);
	print_dll_int((*dll).first);
	printf("\t\tswap first / next:\n");
	swap_node_to_dll(dll, (*dll).first, (*(*dll).first).next);
	print_dll_int((*dll).first);
	printf("\t\tswap prev / last:\n");
	swap_node_to_dll(dll, (*(*dll).last).prev, (*dll).last);
	print_dll_int((*dll).first);
	printf("\t\tswap next / first:\n");
	swap_node_to_dll(dll, (*(*dll).first).next, (*dll).first);
	print_dll_int((*dll).first);
	printf("\t\tswap random / random:\n");
	i = -1;
	(*dll).cursor = (*dll).first;
	while (++i < 5)
		(*dll).cursor = (*(*dll).cursor).next;
	swap_node_to_dll(dll, (*(*dll).cursor).next, (*(*(*dll).first).next).next);
	print_dll_int((*dll).first);
	printf("\t\tswap random / first:\n");
	swap_node_to_dll(dll, (*(*dll).cursor).next, (*dll).first);
	print_dll_int((*dll).first);
	printf("\t\tswap random / last:\n");
	swap_node_to_dll(dll, (*(*dll).cursor).next, (*dll).last);
	print_dll_int((*dll).first);

//destruction
	destroy(dll);

///////////////////////////////////////////////////////////////////////////////
//###################
//#######CHAR########
//###################
//creation of dll
	printf("\tCHAR:\n");
	dll = get_new_dll();
	if (dll == NULL)
		return (ERROR);
//addition of nodes and data
	i = -1;
	while (++i < nb_node)
	{
		if (add_node_to_dll(dll, to_void(data)) == FAIL)
		{
			destroy(dll);
			return (ERROR);
		}
		++data;
	}
//display all nodes
	print_dll_char((*dll).first);
//destruction
	destroy(dll);

///////////////////////////////////////////////////////////////////////////////
//###################
//######STRINGS######
//###################
//creation of dll
	printf("\tSTRINGS:\n");
	dll = get_new_dll();
	if (dll == NULL)
		return (ERROR);
//addition of nodes and data
	if (add_node_to_dll(dll, (void*)string) == FAIL)
	{
		destroy(dll);
		return (ERROR);
	}
	if (add_node_to_dll(dll, (void*)string0) == FAIL)
	{
		destroy(dll);
		return (ERROR);
	}
	if (add_node_to_dll(dll, (void*)string1) == FAIL)
	{
		destroy(dll);
		return (ERROR);
	}
//display all nodes
	print_dll_string((*dll).first);
//destruction
	destroy(dll);
	return (EXIT_SUCCESS);
}

