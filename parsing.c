/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabouelk <sabouelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:31:04 by sabouelk          #+#    #+#             */
/*   Updated: 2025/05/21 20:49:50 by sabouelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/******************** washe the evaluator inputs ************************/

// clean_input()
// {
// -7
//          // white spaces
// j slhf fjsjds // latters 
// % ( ) $ @ _ + // special characters
// ./program.c arg1 arg2 arg3 // more than 2 args
// ./program.c // no numbers intered
// 3 8 1 0 12 87 42 11 10000000000000000 // overflow
// 3 8 1 0 12 87 42 11 7 3 // duplicates
// tybedef
// }
/*
converts a string to a long integer and handles negative numbers and overflow
*/

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/* check input validation
str NOT NULL and have inputs
accept signs (-, +)
only digits from int_min to int_max
*/

bool	is_valid_number(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '\0')
		return (false);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	return (true);
}
/* check for duplicate values in the stack */

bool	check_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	if (stack == NULL || stack->head == NULL)
		return (false);
	current = stack->head;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (true);
			check = check->next;
		}
		current = current->next;
	}
	return (false);
}
/*check if the stack is already sorted*/

bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack_a == NULL || stack->head == NULL)
		return (true);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}
