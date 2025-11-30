
int	is_visible(int arr[4], int pow)
{
	int	i;
	int	max;
	int	vis;

	if (pow == 0)
		return (1);
	i = 0;
	max = 0;
	vis = 0;
	while (i < 4)
	{
		if (arr[i] == 0)
			break ;
		if (arr[i] > max)
		{
			max = arr[i];
			vis++;
		}
		i++;
	}
	if (vis == pow)
		return (1);
	return (0);
}

int	check_left(int row, int grid[4][4], int pow)
{
	int	arr[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		arr[i] = grid[row][i];
		i++;
	}
	return (is_visible(arr, pow));
}

int	check_right(int row, int grid[4][4], int pow)
{
	int	arr[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		arr[i] = grid[row][3 - i];
		i++;
	}
	return (is_visible(arr, pow));
}

int	check_up(int col, int grid[4][4], int pow)
{
	int	arr[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		arr[i] = grid[i][col];
		i++;
	}
	return (is_visible(arr, pow));
}

int	check_down(int col, int grid[4][4], int pow)
{
	int	arr[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		arr[i] = grid[3 - i][col];
		i++;
	}
	return (is_visible(arr, pow));
}
