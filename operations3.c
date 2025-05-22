/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabouelk <sabouelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:00:54 by sabouelk          #+#    #+#             */
/*   Updated: 2025/05/16 20:02:51 by sabouelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rra(t_stack *stack, int print)
{
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->bottom;
	stack->bottom = last->prev;
	stack->bottom->next = NULL;
	last->next = stack->head;
	stack->head->prev = last;
	last->prev = NULL;
	stack->head = last;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack, int print)
{
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->bottom;
	stack->bottom = last->prev;
	stack->bottom->next = NULL;
	last->next = stack->head;
	stack->head->prev = last;
	last->prev = NULL;
	stack->head = last;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
