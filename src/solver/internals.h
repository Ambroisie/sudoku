#ifndef INTERNALS_H
#define INTERNALS_H

#include <stdbool.h>

struct sudoku;

bool update_sets(const struct sudoku *grid, bool possibilities[9][9][9]);
bool single_occurrence(struct sudoku *grid, bool possibilities[9][9][9]);
bool last_remaining(struct sudoku *grid);
bool slice_and_dice(bool possibilities[9][9][9]);

#endif /* !INTERNALS_H */
