#ifndef FT_SIDE_VALIDATOR_H
# define FT_SIDE_VALIDATOR_H

int	col_valid(int row, int col, int grid[4][4], int pows[16]);

int	row_valid(int row, int col, int grid[4][4], int pows[16]);

int	sides_valid(int row, int col, int grid[4][4], int pows[16]);

#endif
