#ifndef FT_SIDE_CHECKER_H
# define FT_SIDE_CHECKER_H

int	is_visible(int arr[4], int pow);

int	check_left(int row, int grid[4][4], int pow);

int	check_right(int row, int grid[4][4], int pow);

int	check_up(int row, int grid[4][4], int pow);

int	check_down(int row, int grid[4][4], int pow);

#endif
