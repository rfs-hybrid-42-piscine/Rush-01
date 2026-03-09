/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:43:43 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/09 21:45:47 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checker(int **cell, int **grid, int size, int index);

/**
 * @fn static void print_solution(int **grid, int size)
 * @brief Iterates and prints the final solved game board.
 * @details Translates the completed 2D integer array into characters, 
 * applying standard space formatting and line breaks per row.
 * @param grid The successfully populated game board.
 * @param size The uniform dimension of the grid.
 */
static void	print_solution(int **grid, int size)
{
	int		row;
	int		col;
	char	c;

	row = -1;
	while (++row < size)
	{
		col = -1;
		while (++col < size)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col == size - 1)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
		}
	}
}

/**
 * @fn static int is_duplicated(int **grid, int size, int index, int guess)
 * @brief Evaluates the uniqueness constraint of the puzzle.
 * @details Scans the target row and column. If the hypothetical `guess`
 * integer already exists within the same axis, it prevents placement.
 * @param grid The current state of the game board.
 * @param size The uniform dimension of the grid.
 * @param index The 1D integer representation of the target placement.
 * @param guess The hypothetical integer (1 to size) attempting placement.
 * @return 1 if a duplicate is found, 0 if it is a legally unique move.
 */
static int	is_duplicated(int **grid, int size, int index, int guess)
{
	int	i;

	i = -1;
	while (++i < size)
		if (grid[index / size][i] == guess || grid[i][index % size] == guess)
			return (1);
	return (0);
}

/**
 * @fn int solve(int **cell, int **grid, int size, int index)
 * @brief Executes the recursive backtracking algorithm.
 * @details  Progresses sequentially through the grid via a 1D index.
 * Attempts to place sequentially ascending integers, checking for duplicates.
 * If valid, it places the piece and recursively calls itself for the next
 * index. If a dead-end is reached, it resets the current placement (0) and
 * backtracks.
 * @param cell The 2D array holding the target boundary constraints.
 * @param grid The current state of the game board.
 * @param size The uniform dimension of the grid.
 * @param index The 1D integer representation of the target placement.
 * @return 1 upon discovering the first viable solution, 0 if impossible.
 */
int	solve(int **cell, int **grid, int size, int index)
{
	int	row;
	int	col;
	int	guess;

	row = index / size;
	col = index % size;
	if (row == size)
	{
		print_solution(grid, size);
		return (1);
	}
	guess = 0;
	while (++guess <= size)
	{
		if (!is_duplicated(grid, size, index, guess))
		{
			grid[row][col] = guess;
			if (checker(cell, grid, size, index)
				&& solve(cell, grid, size, index + 1) == 1)
				return (1);
			grid[row][col] = 0;
		}
	}
	return (0);
}
