project(
  'sudoku',
  'c',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'c_std=c99',
  ],
)

sources = [
  'src/constraints.c',
  'src/main.c',
  'src/solver/last_remaining.c',
  'src/solver/single_occurence.c',
  'src/solver/solve.c',
  'src/solver/update_sets.c',
  'src/sudoku.c',
]

incdir = include_directories(
  'src',
)

executable(
  'sudoku',
  sources : sources,
  c_args : '-D_POSIX_C_SOURCE=200809L',
  include_directories : incdir,
)
