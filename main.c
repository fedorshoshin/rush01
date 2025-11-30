/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:33:25 by anhambar          #+#    #+#             */
/*   Updated: 2025/11/30 19:07:45 by anhambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_side_checker.h"
#include "ft_base_validator.h"
#include "ft_side_validator.h"
#include "ft_grid_printer.h"
/*
int	is_valid(int row, int col, int grid[4][4], int k, int pows[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == k)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] == k)
			return (0);
		i++;
	}
	grid[row][col] = k;
	if (col == 3)
	{
		if (!check_left(row, grid, pows[8 + row]))
		{
			grid[row][col] = 0;
			return (0);
		}
		if (!check_right(row, grid, pows[12 + row]))
		{
			grid[row][col] = 0;
			return (0);
		}
	}
	if (row == 3)
	{
		if (!check_up(col, grid, pows[col]))
		{
			grid[row][col] = 0;
			return (0);
		}
		if (!check_down(col, grid, pows[4 + col]))
		{
			grid[row][col] = 0;
			return (0);
		}
	}
	return (1);
}
*/
int	solve(int row, int col, int grid[4][4], int pows[16])
{
	int	i;

	if (row == 4)
		return (1);
	else if (col == 4)
		return (solve(row + 1, 0, grid, pows));
	else if (grid[row][col] != 0)
		return (solve(row, col + 1, grid, pows));
	i = 1;
	while (i <= 4)
	{
		if (ft_base_valid(row, col, grid, i) == 1 && sides_valid(row, col, grid, pows) == 1)
		{
			grid[row][col] = i;
			if (solve(row, col + 1, grid, pows) == 1)
				return (1);
			grid[row][col] = 0;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	grid[4][4] = {{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0}};
	int	pows[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};

	solve(0, 0, grid, pows);
	ft_print(grid);
	return (0);
}
