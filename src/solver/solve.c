#include "solve.h"

#include <stddef.h>

#include "constraints.h"
#include "internals.h"
#include "sudoku.h"

static void init_possibilities(bool possibilities[9][9][9]) {
    for (size_t i = 0; i < 9; ++i) {
        for (size_t j = 0; j < 9; ++j) {
            for (size_t n = 0; n < 9; ++n) {
                possibilities[i][j][n] = true;
            }
        }
    }
}

bool solve(struct sudoku *grid) {
    if (!grid)
        return false;

    bool possibilities[9][9][9];
    init_possibilities(possibilities);

    bool changed;
    do {
        changed = false;

        changed |= update_sets(grid, possibilities);
    } while (changed);

    return solved(grid);
}
