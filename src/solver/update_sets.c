#include "internals.h"

#include <stddef.h>

#include "sudoku.h"

static bool ensure_unique(bool possibilities[9][9][9], size_t i, size_t j,
                          int num) {
    bool changed = false;

    for (int n = 0; n < 9; ++n) {
        if (n == num)
            continue;
        changed |= possibilities[i][j][n];
        possibilities[i][j][n] = false;
    }

    return changed;
}

static bool update_line(bool possibilities[9][9][9], size_t i, size_t j,
                        int num) {
    bool changed = false;

    for (size_t c = 0; c < 9; ++c) {
        if (c == j)
            continue;
        changed |= possibilities[i][c][num];
        possibilities[i][c][num] = false;
    }

    return changed;
}

static bool update_column(bool possibilities[9][9][9], size_t i, size_t j,
                          int num) {
    bool changed = false;

    for (size_t l = 0; l < 9; ++l) {
        if (l == i)
            continue;
        changed |= possibilities[l][j][num];
        possibilities[l][j][num] = false;
    }

    return changed;
}

static bool update_square(bool possibilities[9][9][9], size_t i, size_t j,
                          int num) {
    bool changed = false;

    const size_t x = i / 3;
    const size_t y = j / 3;

    for (size_t l = 3 * x; l < 3 * (x + 1); ++l) {
        for (size_t c = 3 * y; c < 3 * (y + 1); ++c) {
            if (l == i && c == j)
                continue;
            changed |= possibilities[l][c][num];
            possibilities[l][c][num] = false;
        }
    }

    return changed;
}

bool update_sets(const struct sudoku *grid, bool possibilities[9][9][9]) {
    bool changed = false;

    for (size_t i = 0; i < 9; ++i) {
        for (size_t j = 0; j < 9; ++j) {
            const int val = grid->grid[i][j];
            if (val == 0)
                continue;

            changed |= ensure_unique(possibilities, i, j, val - 1);
            changed |= update_line(possibilities, i, j, val - 1);
            changed |= update_column(possibilities, i, j, val - 1);
            changed |= update_square(possibilities, i, j, val - 1);
        }
    }

    return changed;
}
