#include <stdio.h>

#include "constraints.h"
#include "solver/solve.h"
#include "sudoku.h"

int main(void) {
    struct sudoku grid;

    if (!parse_grid_file(&grid, stdin))
        return 1;

    solve(&grid);

    print_grid(&grid, stdout);

    return !solved(&grid);
}
