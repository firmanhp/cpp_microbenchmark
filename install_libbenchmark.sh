#!/bin/bash

cd "$(dirname "$0")"

# Now this script will always run in its own directory
echo "Current directory: $(pwd)"

# Check out the library.
git clone https://github.com/google/benchmark.git
# Go to the library root directory
cd benchmark
# Make a build directory to place the build output.
cmake -E make_directory "build"
# Generate build system files with cmake, and download any dependencies.
cmake -E chdir "build" cmake -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on -DCMAKE_BUILD_TYPE=Release ../
# or, starting with CMake 3.13, use a simpler form:
# cmake -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on -DCMAKE_BUILD_TYPE=Release -S . -B "build"
# Build the library.
cmake --build "build" --config Release
