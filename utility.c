/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabouelk <sabouelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:42:13 by sabouelk          #+#    #+#             */
/*   Updated: 2025/05/21 20:59:14 by sabouelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_stack	*init_stack(char name)
{
	t_stack	*stack;

	stack = (t_stack *) malloc (sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->name = name;
	return (stack);
}

t_program	*init_program(void)
{
	t_program	*program;

	program = (t_program *) malloc (sizeof(t_program));
	if (!program)
		return (NULL);
	program->stack_a = init_stack('a');
	program->stack_b = init_stack('b');
	if (!program->stack_a || !program->stack_b)
	{
		free_program(program);
		return (NULL);
	}
	program->sorted_array = NULL;
	program->total_size = 0;
	program->op_count = 0;
	return (program);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *) malloc (sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*pop_from_stack(t_stack *stack)
{
	t_node	*target_node;

	if (!stack || !stack->head)
		return (NULL);
	target_node = stack->head;
	stack->head = stack->head->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->bottom = NULL;
	stack->size--;
	target_node->next = NULL;
	target_node->prev = NULL;
	return (target_node);
}

void	push_to_stack(t_stack *stack, t_node	*target_node)
{
	if (!stack || !target_node)
		return ;
	if (stack->head == NULL)
	{
		stack->head = target_node;
		stack->bottom = target_node;
	}
	else
	{
		target_node->next = stack->head;
		stack->head->prev = target_node;
		stack->head = target_node;
	}
	stack->size++;
}
