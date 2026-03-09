/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:43:43 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/09 20:01:17 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checker(int **cell, int **grid, int size, int index);

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

static int	is_duplicated(int **grid, int size, int index, int guess)
{
	int	i;

	i = -1;
	while (++i < size)
		if (grid[index / size][i] == guess || grid[i][index % size] == guess)
			return (1);
	return (0);
}

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
