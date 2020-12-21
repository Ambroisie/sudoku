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
  'src/main.c',
]

executable(
  'sudoku',
  sources : sources,
  c_args : '-D_POSIX_C_SOURCE=200809L',
)
