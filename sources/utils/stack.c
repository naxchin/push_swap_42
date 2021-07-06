#include "../../include/push_swap.h"

t_node* init_linked_list(t_node* head)
{
    head = NULL;
    return(head);
}

/**
 * reverse the element of a stack
*/

void reverse_stack(t_node **tmp)
{
    t_node* prev_ptr = NULL;
    t_node* current = *tmp;
    t_node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev_ptr;

        // Move pointers one position ahead.
        prev_ptr = current;
        current = next;
    }
    *tmp = prev_ptr;
}

/**
 * push an element into stack
*/

// t_node* push(int data, t_node* stack)
// {
//     t_node* new_head = (t_node*)malloc(sizeof(t_node));
//     new_head->data = data;
//     new_head->next = stack;
//     stack = new_head;
//     // free(new_head);
//     // new_head == NULL;
//     return(stack);
// }

void push(int data, t_node** stack)
{
    t_node* new_head = (t_node*)malloc(sizeof(t_node));
    new_head->data = data;
    new_head->next = (*stack);
    (*stack) = new_head;
    // free(new_head);
    // new_head == NULL;
}

/**
 * remove element from the top of the stack
*/
void pop(t_node **stack)
{
    if((*stack) != NULL){
        // printf("Element popped: %d\n",(*stack)->data);
        t_node* tmp = (*stack);
        (*stack) = (*stack)->next;
        // free(tmp);
    }
    else
    {
        printf("The stack is empty.\n");
    }
}

/**
 * display the whole stack
*/
void display_stack(t_node* head)
{
    t_node *current;
    current = head;
    if (current == NULL)
        printf("The Stack is empty\n");
    while (current != NULL)
    {
            printf("stack : %d\n",current->data);
            current = current->next;
    }
}

/**
 * display the element at the top of the stack
*/
void display_head(t_node* stack)
{
    if(stack != NULL)
    {
    printf("Element on top: %d\n", stack->data);
    }
    else{
        printf("The stack is empty.\n");
    }
}

int		is_stack_empty(t_node *stack)
{
	if (stack == NULL)
	{
		pstr("stack is empty");
		return(1);
	}
	return(0);
}

t_node *	build_stack(char *str, int *stack_size)
{
	t_node *stack_a = NULL;
	init_linked_list(stack_a);
	int i;
	i = 0;
    int size = 0;
    if (is_invisible_str(&str[i]) == 1)
        return(0);

    while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && !is_invisible_char(str[i]) && str[i] != '-')
        {
			pstr("not a digit and not a space");
            return(0);
        }
		i++;
	}

	i = 0;
	while (str[i] != '\0')
	{
		while(is_invisible_char(str[i]))
			i++;

        //treat the zero manually because of atoi return value
        if (str[i] == '0')
        {
		    push(0, &stack_a);
            size = 1 + size;
            // i++;
        }
        while(is_invisible_char(str[i]))
			i++;
        //now atoi will return 0 only if there is an error
        if (ft_atoi(&str[i]) != 0)
		{
            push(ft_atoi(&str[i]), &stack_a);
            size = 1 + size;
        }

		while(ft_isdigit(str[i]) || str[i] == '-')
			i++;
	}

    reverse_stack(&stack_a);
    *stack_size = size;

	return(stack_a);
}
