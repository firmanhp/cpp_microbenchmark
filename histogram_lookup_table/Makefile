CC = g++
OUT = out

CCFLAGS = -std=c++20 -I./ -I../benchmark/include -Wextra -O3 -march=native
TEST_CCFLAGS = -Wextra -fsanitize=undefined
BENCH_CCFLAGS = -L../benchmark/build/src/ -lbenchmark  -lpthread 
TARGETS = fast_test fast_bench slow_test slow_bench

COMMON_OBJS = common.o
FAST_OBJS = fast.o
SLOW_OBJS = slow.o

all: $(TARGETS)

%.o : %.cc
	$(CC) $(CCFLAGS) -c $< -o $@

fast_test: $(COMMON_OBJS) test.o fast.o
	$(CC) $^ $(CCFLAGS) $(TEST_CCFLAGS) -o $@

fast_bench: $(COMMON_OBJS) bench.o fast.o
	$(CC) $^ $(CCFLAGS) $(BENCH_CCFLAGS) -o $@

slow_test: $(COMMON_OBJS) test.o slow.o
	$(CC) $^ $(CCFLAGS) $(TEST_CCFLAGS) -o $@

slow_bench: $(COMMON_OBJS) bench.o slow.o
	$(CC) $^ $(CCFLAGS) $(BENCH_CCFLAGS) -o $@

clean:
	rm -f *.o $(TARGETS)

.PHONY: all clean