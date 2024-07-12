# I am putting a meson.build file in the top directory as well as the src 
# directory because I do not want to prepend 'src/' to all the files.
# This can naturally be extended to us putting a meson.build file in all 
# subdirectories of the src folder and putting subdir() calls to all those
# subdirectories in here, but we can equally just put 'foo/bar.c' in the 
# filepath array below.

# Meson requires you to add all source files manually for the sake of speed.
sources = files([
  'main.c',
])