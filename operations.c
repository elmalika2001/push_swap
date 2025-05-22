/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabouelk <sabouelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 05:35:18 by sabouelk          #+#    #+#             */
/*   Updated: 2025/05/21 20:56:25 by sabouelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_stack *stack_a, int print)
{
	int	temp;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	temp = stack_a->head->value;
	stack_a->head->value = stack_a->head->next->value;
	stack_a->head->next->value = temp;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack_b, int print)
{
	int	temp;

	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	temp = stack_b->head->value;
	stack_b->head->value = stack_b->head->next->value;
	stack_b->head->next->value = temp;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	sa (stack_a, 0);
	sb (stack_b, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack *stack_a, t_stack *stack_b, int print)

{
	t_node	*node;

	if (!stack_b || !stack_b->head)
		return ;
	node = pop_from_stack(stack_b);
	push_to_stack(stack_a, node);
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_node	*node;

	if (!stack_a || !stack_a->head)
		return ;
	node = pop_from_stack(stack_a);
	push_to_stack(stack_b, node);
	if (print)
		ft_putstr_fd ("pb\n", 1);
}
