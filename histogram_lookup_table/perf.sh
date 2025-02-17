#!/bin/bash
set -x
perf stat -e cycles,instructions,branches,branch-misses,cache-references,cache-misses $@
