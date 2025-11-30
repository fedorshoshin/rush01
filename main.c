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

#include <stdlib.h>

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
		if (is_valid(row, col, grid, i, pows	))
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

int *ft_parse_input(char *input)
{
    int *povs;
    int i;

    povs = malloc(16 * 4);
    if (!povs)
        return ;

    i = 0;
    while (*input != '\0')
    {
        if (*input >= '0' && *input <= '9')
        {
            if (i >= 16)
            {
                return ;
            }
            povs[i] = *input - '0';
            i++;
        }
        input++;
    }

    if (i != 16)
    {
        return ;
    }

    return (povs);
}

int	main(int argc, char **argv)
{
	int	grid[4][4] = {{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0}};
	int	*pows;

	if(argc != 2)
		return;
	pows = ft_parse_input(argv[1]);
	solve(0, 0, grid, pows);
	ft_print(grid);
	return (0);
}
