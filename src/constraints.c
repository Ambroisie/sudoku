#include "constraints.h"

#include "sudoku.h"

bool line_violation(const struct sudoku *grid, size_t i, size_t j) {
    if (!grid)
        return true;

    for (size_t l = 0; l < 9; ++l) {
        if (l == i)
            continue;
        if (grid->grid[l][j] == grid->grid[i][j])
            return true;
    }

    return false;
}

bool column_violation(const struct sudoku *grid, size_t i, size_t j) {
    if (!grid)
        return true;

    for (size_t c = 0; c < 9; ++c) {
        if (c == j)
            continue;
        if (grid->grid[i][c] == grid->grid[i][j])
            return true;
    }

    return false;
}

bool square_violation(const struct sudoku *grid, size_t i, size_t j) {
    if (!grid)
        return true;

    const size_t x = i / 3;
    const size_t y = j / 3;

    for (size_t l = 3 * x; l < 3 * (x + 1); ++l) {
        for (size_t c = 3 * y; c < 3 * (y + 1); ++c) {
            if (l == i && c == j)
                continue;
            if (grid->grid[l][c] == grid->grid[i][j])
                return true;
        }
    }

    return false;
}
