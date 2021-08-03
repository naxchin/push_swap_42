#ifndef SORT_H
# define SORT_H
# include "struct.h"

void two_value_sort(t_node **stack_a, int n_elem);
void	three_nb_sort(t_node **stack_a);
void	radix_sort(t_node **stack_a, int count);
void	test_radix_sort(char *list_nb);
int		find_pos(t_node * list, int value);
void	find_smallest_nb(t_node *list, int *s_value, int *s_pos);
void	find_biggest_nb(t_node *list, int *b_value, int *b_pos);
void	four_nb_sort(t_node **stack_a, t_node**stack_b, int i);
void	five_nb_sort(t_node **stack_a, t_node**stack_b, int i);
void	five_or_four_nb(t_node **stack_a, int count);

void	sorting_five(t_node ** stack_a, t_node ** stack_b);
int		get_last_value(t_node *stack);
int		insertion_sort(t_node **stack_a, int total_nb);

int	find_smallest_nb_above_x(t_node*stack, int x, int * total_node);
void rotate_number_to_top(t_node **stack_a, int pos, int total_node);


void	multiple_rotations_on_a(t_node **stack_a, char *action, int number_of_time);
void	insert_nb_in_middles(t_node**stack_a, t_node **stack_b);

int 	insert_nb_in_extremities(t_node**stack_a, t_node **stack_b, int total_nb);
void	multiple_rotations_on_a(t_node **stack_a, char *action, int number_of_time);
void	insert_nb_from_b_to_a(t_node **stack_a, t_node **stack_b, int *total_nb);

void	move_min_value_to_top(t_node** stack, int total_node);

#endif
