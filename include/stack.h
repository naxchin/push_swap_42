#ifndef STACK_H
# define STACK_H
# include "struct.h"


t_node*		init_linked_list(t_node* head);
void		push(int data, t_node** stack);
void		pop(t_node **stack);
void		display_stack(t_node* head);
void		display_head(t_node* stack);
void 		printReverse(t_node* head);
int			is_stack_empty(t_node *stack);
t_node *	build_stack(char *str, int argc);



#endif
