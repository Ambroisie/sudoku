#include "internals.h"

#include <stddef.h>

#include "sudoku.h"

static bool single_line(struct sudoku *grid, bool possibilities[9][9][9],
                        size_t i, size_t j) {
    for (int n = 0; n < 9; ++n) {
        if (!possibilities[i][j][n])
            continue;

        bool unique = true;
        for (size_t c = 0; c < 9; ++c) {
            if (c == j)
                continue;
            unique &= !possibilities[i][c][n];
        }
        if (!unique)
            continue;

        grid->grid[i][j] = n + 1;
        return true;
    }

    return false;
}

static bool single_column(struct sudoku *grid, bool possibilities[9][9][9],
                          size_t i, size_t j) {
    for (int n = 0; n < 9; ++n) {
        if (!possibilities[i][j][n])
            continue;

        bool unique = true;
        for (size_t l = 0; l < 9; ++l) {
            if (l == i)
                continue;
            unique &= !possibilities[l][j][n];
        }
        if (!unique)
            continue;

        grid->grid[i][j] = n + 1;
        return true;
    }

    return false;
}

static bool single_square(struct sudoku *grid, bool possibilities[9][9][9],
                          size_t i, size_t j) {
    const size_t x = i / 3;
    const size_t y = j / 3;

    for (int n = 0; n < 9; ++n) {
        if (!possibilities[i][j][n])
            continue;

        bool unique = true;
        for (size_t l = 3 * x; l < 3 * (x + 1); ++l) {
            for (size_t c = 3 * y; c < 3 * (y + 1); ++c) {
                if ((l == i) && (c == j))
                    continue;
                unique &= !possibilities[i][c][n];
            }
        }
        if (!unique)
            continue;

        grid->grid[i][j] = n + 1;
        return true;
    }

    return false;
}

bool single_occurrence(struct sudoku *grid, bool possibilities[9][9][9]) {
    bool changed = false;

    for (size_t i = 0; i < 9; ++i) {
        for (size_t j = 0; j < 9; ++j) {
            if (grid->grid[i][j] != 0)
                continue;
            changed |= single_line(grid, possibilities, i, j)
                       || single_column(grid, possibilities, i, j)
                       || single_square(grid, possibilities, i, j);
        }
    }

    return changed;
}
