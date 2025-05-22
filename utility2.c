/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabouelk <sabouelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:55:13 by sabouelk          #+#    #+#             */
/*   Updated: 2025/05/21 21:00:59 by sabouelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_program(t_program *program)
{
	t_node	*current_node;

	if (!program)
		return ;
	printf("stack A (size: %d):", program->stack_a->size);
	current_node = program->stack_a->head;
	while (current_node)
	{
		printf("%d, ", current_node->value);
		current_node = current_node->next;
	}
	printf("\n");
	current_node = program->stack_b->head;
	printf("stack B (size: %d):", program->stack_b->size);
	while (current_node)
	{
		printf("%d, ", current_node->value);
		current_node = current_node->next;
	}
	printf("\n");
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp_node;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		temp_node = current;
		current = current->next;
		free(temp_node);
	}
	free(stack);
}

void	free_program(t_program *program)
{
	if (!program)
		return ;
	if (program->stack_a)
		free_stack(program->stack_a);
	if (program->stack_b)
		free_stack(program->stack_b);
	if (program->sorted_array)
		free(program->sorted_array);
	free(program);
}

void	ft_putstr_fd(char *str, int fd)
{
	(void)fd;
	printf("%s", str);
}
