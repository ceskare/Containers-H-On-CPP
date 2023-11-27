CFLAGS = g++ -Wall -Wextra -Werror -std=c++17 -O3
TFLAGS = -lgtest -ftest-coverage -fprofile-arcs
GFLAGS = --no-external -c -d .
TEST_C = $(shell find tests -name "*.cc")
OS := $(shell uname -s)

ifeq ($(OS),Darwin)
	OPEN_CMD = open
	GFLAGS += --ignore-errors mismatch
else
	TFLAGS += -lm -lrt -lsubunit -lpthread
	OPEN_CMD = xdg-open
endif

all: clean test

clang:
	clang-format --style=Google -i $(shell find . -name "*.cc" -o -name "*.h" -o -name "*.tpp")

test:
	$(CFLAGS) $(TEST_C) -o tests.out $(TFLAGS) -lpthread
	./tests.out

gcov_report: clean test
	lcov -t "./tests.out"  -o report.info $(GFLAGS)
	genhtml -o report report.info
	$(OPEN_CMD) ./report/index.html

	rm -rf *.gcno *gcda *.gco


valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./tests.out

clean:
	rm -rf $(shell find . -name "*.o") *.a *.out *.gcda *.gcno *.info report