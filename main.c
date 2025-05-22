/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabouelk <sabouelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:31:11 by sabouelk          #+#    #+#             */
/*   Updated: 2025/05/21 20:43:02 by sabouelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	t_program	*program;
	t_node		*node;

	program = init_program();
	if (!program)
		return (1);
	node = create_node(3);
	push_to_stack(program->stack_a, node);
	node = create_node(9);
	push_to_stack(program->stack_a, node);
	node = create_node(1);
	push_to_stack(program->stack_a, node);
	// Print initial state
	printf("Initial state:\n");
	print_program(program);
	// Tests (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr)
	printf("Test operation sa:\n");
	sa(program->stack_a, 1);
	print_program(program);
	// Free memory
	free_program(program);
	return (0);
}
