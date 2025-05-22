/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabouelk <sabouelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:48:49 by sabouelk          #+#    #+#             */
/*   Updated: 2025/05/16 20:01:24 by sabouelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ra(t_stack *stack_a, int print)
{
	t_node	*first;

	if (!stack_a || stack_a->size < 2)
		return ;
	first = stack_a->head;
	stack_a->head = first->next;
	stack_a->head->prev = NULL;
	stack_a->bottom->next = first;
	first->prev = stack_a->bottom;
	first->next = NULL;
	stack_a->bottom = first;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack, int print)
{
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	stack->head = first->next;
	stack->head->prev = NULL;
	stack->bottom->next = first;
	first->prev = stack->bottom;
	first->next = NULL;
	stack->bottom = first;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		ft_putstr_fd("rr\n", 0);
}
