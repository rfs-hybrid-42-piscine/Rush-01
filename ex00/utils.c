/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:55:43 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/09 20:00:47 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

void	free_matrix(int **array, int index)
{
	while (index > 0)
		free(array[--index]);
	free(array);
}

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
