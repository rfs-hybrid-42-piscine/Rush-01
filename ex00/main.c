/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:18:37 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/09 21:22:47 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_isspace(int c);
int		**initialize_matrix(int rows, int cols);
void	free_matrix(int **array, int index);
int		solve(int **cell, int **grid, int size, int index);

static int	print_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

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
	{
		if (cell)
			free_matrix(cell, 4);
		return (print_error());
	}
	grid = initialize_matrix(count / 4, count / 4);
	if (!grid || !solve(cell, grid, count / 4, 0))
	{
		if (grid)
			free_matrix(grid, count / 4);
		return (free_matrix(cell, 4), print_error());
	}
	return (free_matrix(grid, count / 4), free_matrix(cell, 4), 0);
}
