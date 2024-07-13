# Define the project.
project('mgec', 'c', version: '0.1', license: 'MIT', license_files: ['LICENSE'])

# Deps
unity = dependency('unity')

# Tell meson the include dir and where the source dir is.
include_dirs = include_directories('include')
subdir('src')

# Define the target executable.
mgec_exe = executable('mgec', sources, include_directories: include_dirs)

# Tests
cpu_test = executable(
  'cpu_test',
  ['test/test_cpu.c', 'src/cpu.c'],
  include_directories: include_dirs,
  dependencies: unity,
)
test('CPU Tests', cpu_test)