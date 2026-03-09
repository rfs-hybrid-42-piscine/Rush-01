/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:14:07 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/09 21:16:20 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
