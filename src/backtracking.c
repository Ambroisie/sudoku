#include "backtracking.h"

#include <stddef.h>

#include "constraints.h"
#include "sudoku.h"

static bool try_at(struct sudoku *grid, size_t i, size_t j, int n) {
    grid->grid[i][j] = n;
    return !(line_violation(grid, i, j) || column_violation(grid, i, j)
             || square_violation(grid, i, j));
}

bool solve_backtracking(struct sudoku *grid) {
    if (!grid)
        return false;

    for (size_t i = 0; i < 9; ++i) {
        for (size_t j = 0; j < 9; ++j) {
            if (grid->grid[i][j] != 0)
                continue;

            for (int n = 1; n <= 9; ++n) {
                if (!try_at(grid, i, j, n))
                    continue;
                if (solve_backtracking(grid))
                    return true;
            }

            grid->grid[i][j] = 0;
            return false;
        }
    }

    return true;
}
