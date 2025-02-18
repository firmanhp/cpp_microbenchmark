#!/bin/bash
set -x
perf stat -e cycles,instructions,branches,branch-misses,cache-references,cache-misses,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses $@
