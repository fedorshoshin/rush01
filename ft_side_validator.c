
int	col_valid(int row, int col, int grid[4][4], int pows[16])
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
	return (1);
}

int	row_valid(int row, int col, int grid[4][4], int pows[16])
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
	return (1);
}

int	sides_valid(int row, int col, int grid[4][4], int pows[16])
{
	if (col == 3)
	{
		if (col_valid(row, col, grid, pows) == 0)
			return (0);
	}
	if (row == 3)
	{
		if (row_valid(row, col, grid, pows) == 0)
			return (0);
	}
	return (1);
}
