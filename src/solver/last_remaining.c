#include "internals.h"

#include <stddef.h>

#include "sudoku.h"

static bool last_line(struct sudoku *grid, size_t i, size_t j) {
    size_t numbers = 9 * 10 / 2; // Sum from 1 to 9
    size_t remaining = 9;
    for (size_t c = 0; c < 9; ++c) {
        if (c == j)
            continue;
        numbers -= grid->grid[i][c];
        remaining -= grid->grid[i][c] != 0;
    }

    if (remaining != 1)
        return false;

    grid->grid[i][j] = numbers;
    return true;
}

static bool last_column(struct sudoku *grid, size_t i, size_t j) {
    size_t numbers = 9 * 10 / 2; // Sum from 1 to 9
    size_t remaining = 9;
    for (size_t l = 0; l < 9; ++l) {
        if (l == i)
            continue;
        numbers -= grid->grid[l][j];
        remaining -= grid->grid[l][j] != 0;
    }

    if (remaining != 1)
        return false;

    grid->grid[i][j] = numbers;
    return true;
}

static bool last_square(struct sudoku *grid, size_t i, size_t j) {
    const size_t x = i / 3;
    const size_t y = j / 3;

    size_t numbers = 9 * 10 / 2; // Sum from 1 to 9
    size_t remaining = 9;
    for (size_t l = 3 * x; l < 3 * (x + 1); ++l) {
        for (size_t c = 3 * y; c < 3 * (y + 1); ++c) {
            if ((l == i) && (c == j))
                continue;
            numbers -= grid->grid[l][c];
            remaining -= grid->grid[l][c] != 0;
        }
    }

    if (remaining != 1)
        return false;

    grid->grid[i][j] = numbers;
    return true;
}

bool last_remaining(struct sudoku *grid) {
    bool changed = false;

    for (size_t i = 0; i < 9; ++i) {
        for (size_t j = 0; j < 9; ++j) {
            if (grid->grid[i][j] != 0)
                continue;
            changed |= last_line(grid, i, j) || last_column(grid, i, j)
                       || last_square(grid, i, j);
        }
    }

    return changed;
}
