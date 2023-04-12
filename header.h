#ifndef HEADER_H
#define HEADER_H
#define ERROR 1
#define FAIL 0
#define	SUCCES 1
/*Header file for doubly linked list*/

typedef struct dll_node //content of a node.
{
	void			*data;
	struct dll_node	*next;
	struct dll_node	*prev;
} t_dll_node;

typedef struct dll_flc //Pointers to specific nodes of the doubly linked liste.
{
	t_dll_node	*first;
	t_dll_node	*last;
	t_dll_node	*cursor;
} t_dll;

/*Functions' prototypes*/

t_dll	*get_new_dll(void);
void	*to_void(int data);
char	add_node_to_dll(t_dll *dll, void *data);
void	remove_node_to_dll(t_dll *dll);
char	insert_node_to_dll(t_dll *dll, void *data);
void	swap_node_to_dll(t_dll *dll, t_dll_node *node1, t_dll_node *node2);
void	destroy(t_dll *dll);
void	print_dll_int(t_dll_node *cursor);
void	print_dll_char(t_dll_node *cursor);
void	print_dll_string(t_dll_node *cursor);
void	print_dll_double(t_dll_node *cursor);
#endif

