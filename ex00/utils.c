/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:55:43 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/09 21:46:32 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @fn int ft_isspace(int c)
 * @brief Evaluates whether a character is standard whitespace.
 * @details Checks for space, tab, newline, vertical tab, feed, and carriage
 * return.
 * @param c The character to evaluate.
 * @return 1 if it is a whitespace character, 0 otherwise.
 */
int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

/**
 * @fn void free_matrix(int **array, int index)
 * @brief Safely deallocates a dynamically created 2D array.
 * @details Iterates down through the allocated dimension size to free
 * individual pointers before finally freeing the master array.
 * @param array A double pointer representing the 2D matrix block.
 * @param index The current maximum allocated size of the array.
 */
void	free_matrix(int **array, int index)
{
	while (index > 0)
		free(array[--index]);
	free(array);
}

/**
 * @fn int **initialize_matrix(int rows, int cols)
 * @brief Dynamically allocates memory for a 2D matrix.
 * @details Uses malloc to create row pointers and individual column arrays,
 * explicitly filling every coordinate with 0 to safely prepare the memory
 * block. Leverages free_matrix upon any allocation failure to prevent memory
 * leaks.
 * @param rows The desired height of the matrix.
 * @param cols The desired width of the matrix.
 * @return A fully prepared double pointer, or NULL if memory fails.
 */
int	**initialize_matrix(int rows, int cols)
{
	int	**matrix;
	int	i;
	int	j;

	matrix = malloc(sizeof(int *) * rows);
	if (!matrix)
		return (0);
	i = -1;
	while (++i < rows)
	{
		matrix[i] = malloc(sizeof(int) * cols);
		if (!matrix[i])
		{
			free_matrix(matrix, i);
			return (NULL);
		}
		j = -1;
		while (++j < cols)
			matrix[i][j] = 0;
	}
	return (matrix);
}
