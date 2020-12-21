#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdbool.h>
#include <stdio.h>

struct sudoku {
    int grid[9][9];
};

bool parse_grid_file(struct sudoku *grid, FILE *input);
bool parse_grid_str(struct sudoku *grid, const char *input);
bool parse_line_file(struct sudoku *grid, FILE *input);
bool parse_line_str(struct sudoku *grid, const char *input);

#endif /* !SUDOKU_H */
