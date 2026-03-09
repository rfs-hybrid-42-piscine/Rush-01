/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:14:07 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/09 21:38:17 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @fn static int check_col_up(int **cell, int **grid, int size, int col)
 * @brief Validates the visibility of a column from the top down.
 * @details Simulates a line of sight from the top of the grid. It tracks the
 * highest building seen so far. If a new building is taller, it increments
 * the visibility count and updates the max height.
 * @param cell The 2D array holding the target boundary constraints.
 * @param grid The current state of the game board.
 * @param size The uniform dimension of the grid.
 * @param col The specific column index being validated.
 * @return 1 if the visible count matches the constraint, 0 otherwise.
 */
static int	check_col_up(int **cell, int **grid, int size, int col)
{
	int	max;
	int	count;
	int	i;

	max = grid[0][col];
	count = 1;
	i = 0;
	while (++i < size)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			count++;
		}
	}
	if (cell[0][col] != count)
		return (0);
	return (1);
}

/**
 * @fn static int check_col_down(int **cell, int **grid, int size, int col)
 * @brief Validates the visibility of a column from the bottom up.
 * @details Iterates in reverse from the bottom of the grid, tracking the
 * tallest building encountered and matching it against the bottom constraint.
 * @param cell The 2D array holding the target boundary constraints.
 * @param grid The current state of the game board.
 * @param size The uniform dimension of the grid.
 * @param col The specific column index being validated.
 * @return 1 if the visible count matches the constraint, 0 otherwise.
 */
static int	check_col_down(int **cell, int **grid, int size, int col)
{
	int	max;
	int	count;
	int	i;

	max = grid[size - 1][col];
	count = 1;
	i = size - 1;
	while (i-- > 0)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			count++;
		}
	}
	if (cell[1][col] != count)
		return (0);
	return (1);
}

/**
 * @fn static int check_row_left(int **cell, int **grid, int size, int row)
 * @brief Validates the visibility of a row from left to right.
 * @details Evaluates the specified row from the first index, counting
 * sequential height increases to verify against the left-side constraint.
 * @param cell The 2D array holding the target boundary constraints.
 * @param grid The current state of the game board.
 * @param size The uniform dimension of the grid.
 * @param row The specific row index being validated.
 * @return 1 if the visible count matches the constraint, 0 otherwise.
 */
static int	check_row_left(int **cell, int **grid, int size, int row)
{
	int	max;
	int	count;
	int	i;

	max = grid[row][0];
	count = 1;
	i = 0;
	while (++i < size)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			count++;
		}
	}
	if (cell[2][row] != count)
		return (0);
	return (1);
}

/**
 * @fn static int check_row_right(int **cell, int **grid, int size, int row)
 * @brief Validates the visibility of a row from right to left.
 * @details Evaluates the specified row in reverse, counting sequential height
 * increases to verify against the right-side boundary constraint.
 * @param cell The 2D array holding the target boundary constraints.
 * @param grid The current state of the game board.
 * @param size The uniform dimension of the grid.
 * @param row The specific row index being validated.
 * @return 1 if the visible count matches the constraint, 0 otherwise.
 */
static int	check_row_right(int **cell, int **grid, int size, int row)
{
	int	max;
	int	count;
	int	i;

	max = grid[row][size - 1];
	count = 1;
	i = size - 1;
	while (i-- > 0)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			count++;
		}
	}
	if (cell[3][row] != count)
		return (0);
	return (1);
}

/**
 * @fn int checker(int **cell, int **grid, int size, int index)
 * @brief Evaluates boundary constraints for completely populated lines.
 * @details Highly optimized to bypass unnecessary checks. It only triggers
 * the rigorous line-of-sight visibility functions if the current index
 * signifies the absolute end of a row or the end of a column.
 * @param cell The 2D array holding the target boundary constraints.
 * @param grid The current state of the game board.
 * @param size The uniform dimension of the grid.
 * @param index The 1D integer representation of the current grid placement.
 * @return 1 if all constraints are perfectly met or deferred, 0 if invalid.
 */
int	checker(int **cell, int **grid, int size, int index)
{
	int	row;
	int	col;

	row = index / size;
	col = index % size;
	if (col == size - 1)
		if (!check_row_left(cell, grid, size, row)
			|| !check_row_right(cell, grid, size, row))
			return (0);
	if (row == size - 1)
		if (!check_col_up(cell, grid, size, col)
			|| !check_col_down(cell, grid, size, col))
			return (0);
	return (1);
}
