/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:18:37 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/09 21:47:10 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_isspace(int c);
int		**initialize_matrix(int rows, int cols);
void	free_matrix(int **array, int index);
int		solve(int **cell, int **grid, int size, int index);

/**
 * @fn static int print_error(void)
 * @brief Standardized error printer.
 * @details Fulfills the subject requirement to print strictly "Error\n" upon
 * any invalid input or unsolvable configuration.
 * @return Always returns 1 to cascade failures up the call stack.
 */
static int	print_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

/**
 * @fn static int error_and_free(int **grid, int **cell, int size)
 * @brief Safely deallocates memory and triggers the standard error output.
 * @details Consolidates the cleanup of dynamically allocated grid and
 * constraint matrices before cascading the failure state via print_error().
 * This prevents memory leaks during initialization or solving failures.
 * @param grid The dynamically allocated game board (NULL if not yet created).
 * @param cell The dynamically allocated constraint map.
 * @param size The calculated dimension of the matrix arrays.
 * @return 1 via the print_error cascade.
 */
static int	error_and_free(int **cell, int **grid, int size)
{
	if (cell)
		free_matrix(cell, 4);
	if (grid)
		free_matrix(grid, size);
	return (print_error());
}

/**
 * @fn static int parser(char *input, int **cell, int size, int index)
 * @brief Recursively parses the formatted string into the constraint matrix.
 * @details Bypasses space characters and sequentially drops valid boundary
 * constraints into the 4 rows of the `cell` matrix. Validates single digits.
 * @param input The raw argument string containing the numbers.
 * @param cell The 2D array designed to hold the parsed constraints.
 * @param size The calculated dimension of the grid.
 * @param index The recursive placement tracker.
 * @return 1 if successfully parsed without trailing garbage, 0 otherwise.
 */
static int	parser(char *input, int **cell, int size, int index)
{
	while (ft_isspace(*input))
		input++;
	if (!*input || index == size * 4)
		return (!*input && index == size * 4);
	if (*input >= '1' && *input <= size + '0'
		&& (ft_isspace(*(input + 1)) || !*(input + 1)))
	{
		cell[index / size][index % size] = *input - '0';
		return (parser(input + 1, cell, size, index + 1));
	}
	return (0);
}

/**
 * @fn static int count_words(char const *str)
 * @brief Determines the total number of constraint tokens provided.
 * @details Evaluates the argument string to count valid space-separated tokens.
 * This enables dynamic allocation for grid sizes from 4x4 up to 9x9.
 * @param str The raw argument string.
 * @return The integer count of discrete tokens found.
 */
static int	count_words(char const *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!ft_isspace(*str) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (ft_isspace(*str))
			in_word = 0;
		str++;
	}
	return (count);
}

/**
 * @fn int main(int argc, char **argv)
 * @brief Entry point and orchestration for the Rush 01 solver.
 * @details Manages dynamic memory allocation, ensures arguments fit within
 * valid sizing boundaries, triggers the parser, and initiates the solver.
 * @param argc The number of command line arguments.
 * @param argv An array of argument strings.
 * @return 0 upon successful solving, 1 upon error.
 */
int	main(int argc, char **argv)
{
	int	**cell;
	int	**grid;
	int	count;

	if (argc != 2)
		return (print_error());
	count = count_words(argv[1]);
	if (count / 4 < 1 || count / 4 > 9 || count % 4 != 0)
		return (print_error());
	cell = initialize_matrix(4, count / 4);
	if (!cell || !parser(argv[1], cell, count / 4, 0))
		return (error_and_free(cell, NULL, count / 4));
	grid = initialize_matrix(count / 4, count / 4);
	if (!grid || !solve(cell, grid, count / 4, 0))
		return (error_and_free(cell, grid, count / 4));
	free_matrix(cell, 4);
	free_matrix(grid, count / 4);
	return (0);
}
