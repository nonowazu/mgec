# Define the project.
project(
  'mgec', 
  'c', 
  version: '0.1',
  license: 'MIT',
  license_files: ['LICENSE']
)

# Tell meson the include dir and where the source dir is.
include_dirs = include_directories('include')
subdir('src')

# Define the target executable.
mgec_exe = executable(
  'mgec', 
  sources, 
  include_directories: include_dirs
)

# We could now run tests if we had test executables
#test('does it run', mgec_exe)

# To set up the project, run meson setup <builddir> in the directory 
# containing this file. To compile it afterwards, run 
# meson compile -C <builddir>. 