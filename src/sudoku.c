#include "sudoku.h"

#include <stdio.h>

#define INPUT_PATTERN "%1d %1d %1d %1d %1d %1d %1d %1d %1d\n"

bool parse_grid_file(struct sudoku *grid, FILE *input) {
    if (!input || !grid)
        return false;

    for (size_t i = 0; i < 9; ++i) {
        int *line = grid->grid[i];

        if (fscanf(input, INPUT_PATTERN, &line[0], &line[1], &line[2], &line[3],
                   &line[4], &line[5], &line[6], &line[7], &line[8])
            < 9)
            return false;
    }

    return true;
}

bool parse_grid_str(struct sudoku *grid, const char *input) {
    if (!input || !grid)
        return false;

    for (size_t i = 0; i < 9; ++i) {
        int *line = grid->grid[i];

        if (sscanf(input, INPUT_PATTERN, &line[0], &line[1], &line[2], &line[3],
                   &line[4], &line[5], &line[6], &line[7], &line[8])
            < 9)
            return false;
    }

    return true;
}
