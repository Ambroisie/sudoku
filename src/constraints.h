#ifndef CONSTRAINTS_H
#define CONSTRAINTS_H

#include <stdbool.h>
#include <stddef.h>

struct sudoku;

bool line_violation(const struct sudoku *grid, size_t i, size_t j);
bool column_violation(const struct sudoku *grid, size_t i, size_t j);
bool square_violation(const struct sudoku *grid, size_t i, size_t j);

bool solved(const struct sudoku *grid);

#endif /* !CONSTRAINTS_H */
