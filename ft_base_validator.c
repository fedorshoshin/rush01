#include "ft_base_validator.h"

int	ft_base_valid(int row, int col, int grid[4][4], int k)
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
	return (1);
}
