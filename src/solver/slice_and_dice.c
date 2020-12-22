#include "internals.h"

#include <stddef.h>

#include "sudoku.h"

static bool slice_line(bool possibilities[9][9][9], size_t x, size_t y) {
    bool changed = false;

    for (int n = 0; n < 9; ++n) {
        size_t line = -1;
        bool unique = true;

        for (size_t i = 3 * x; i < 3 * (x + 1); ++i) {
            for (size_t j = 3 * y; j < 3 * (y + 1); ++j) {
                if (!possibilities[i][j][n])
                    continue;
                if (line >= 9)
                    line = i;
                else if (line != i)
                    unique = false;
            }
        }

        if (line >= 9 || !unique)
            continue;

        for (size_t c = 0; c < 9; ++c) {
            if ((c / 3) == y)
                continue;
            changed |= possibilities[line][c][n];
            possibilities[line][c][n] = false;
        }
    }

    return changed;
}

static bool slice_column(bool possibilities[9][9][9], size_t x, size_t y) {
    bool changed = false;

    for (int n = 0; n < 9; ++n) {
        size_t column = -1;
        bool unique = true;

        for (size_t i = 3 * x; i < 3 * (x + 1); ++i) {
            for (size_t j = 3 * y; j < 3 * (y + 1); ++j) {
                if (!possibilities[i][j][n])
                    continue;
                if (column >= 9)
                    column = j;
                else if (column != j)
                    unique = false;
            }
        }

        if (column >= 9 || !unique)
            continue;

        for (size_t l = 0; l < 9; ++l) {
            if ((l / 3) == x)
                continue;
            changed |= possibilities[l][column][n];
            possibilities[l][column][n] = false;
        }
    }

    return changed;
}

bool slice_and_dice(bool possibilities[9][9][9]) {
    bool changed = false;

    for (size_t x = 0; x < 3; ++x) {
        for (size_t y = 0; y < 3; ++y) {
            changed |= slice_line(possibilities, x, y);
            changed |= slice_column(possibilities, x, y);
        }
    }

    return changed;
}
