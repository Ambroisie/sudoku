#include <stdio.h>

#include "backtracking.h"
#include "constraints.h"
#include "solver/solve.h"
#include "sudoku.h"

int main(void) {
    struct sudoku grid;

    if (!parse_grid_file(&grid, stdin))
        return 1;

    solve_backtracking(&grid);

    print_grid(&grid, stdout);

    return !solved(&grid);
}
