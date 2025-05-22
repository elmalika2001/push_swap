/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabouelk <sabouelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:21:05 by sabouelk          #+#    #+#             */
/*   Updated: 2025/05/21 21:01:34 by sabouelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/*libs*/
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
/******************** Node structure ************************/
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;
/******************** stack structure ************************/
typedef struct s_stack
{
	t_node	*head;
	t_node	*bottom;
	int		size;
	char	name;
}	t_stack;
/******************** the whole program structure ************************/
typedef struct s_program
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted_array;
	int		total_size;
	int		op_count;
}	t_program;
/******************** each element costs structure ************************/
typedef struct s_cost
{
	int	index;
	int	cost_a;
	int	cost_b;
	int	total_cost;
}	t_cost;
/******************** Declare Functions ************************/
void		print_program(t_program *program);
void		free_stack(t_stack *stack);
void		free_program(t_program *program);
void		push_to_stack(t_stack *stack, t_node	*target_node);
t_node		*pop_from_stack(t_stack *stack);
t_node		*create_node(int value);
t_program	*init_program(void);
t_stack		*init_stack(char name);
void		rra(t_stack *stack, int print);
void		rrb(t_stack *stack, int print);
void		rrr(t_stack *stack_a, t_stack *stack_b, int print);
void		ra(t_stack *stack_a, int print);
void		rb(t_stack *stack, int print);
void		rr(t_stack *stack_a, t_stack *stack_b, int print);
void		sa(t_stack *stack_a, int print);
void		pb(t_stack *stack_a, t_stack *stack_b, int print);
void		pa(t_stack *stack_a, t_stack *stack_b, int print);
void		ss(t_stack *stack_a, t_stack *stack_b, int print);
void		sb(t_stack *stack_b, int print);
void		ft_putstr_fd(char *str, int fd);
#endif