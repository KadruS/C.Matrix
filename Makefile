CFLAGS = -std=c11 -Wall -Werror -Wextra
FLAG_TEST = -lcheck
SRCS = $(wildcard s21_*.c)
OBJS = $(SRCS:.c =.o)
TESTS = tests/*tests.c
LEAKS = leaks -atExit --

ifeq ($(shell uname), Linux)
	FLAG_TEST += -lsubunit -lm
	LEAKS = valgrind --tool=memcheck --leak-check=yes
endif

all: test

s21_matrix.a: $(OBJS)
	ar -rc s21_matrix.a $^
	ranlib s21_matrix.a
	rm -rf *.o

test: clean s21_matrix.a
	mkdir test
	gcc --coverage $(SRCS) $(TESTS) $(FLAG_TEST) -o test/test
	test/test

gcov_report:
	mkdir greport
	gcc --coverage $(SRCS) $(TESTS) $(FLAG_TEST) -o greport/greport
	./greport/greport
	lcov -t "test" -o s21_matrix.info -c -d .
	genhtml -o ./report s21_matrix.info
	open ./report/index.html

style:
	clang-format -n --style=google *.c *.h ./tests/*.c ./tests/*.h
	clang-format -i --style=google *.c *.h ./tests/*.c ./tests/*.h

leaks: clean s21_matrix.a
	mkdir test
	gcc --coverage $(SRCS) $(TESTS) $(FLAG_TEST) -o test/test
	$(LEAKS) ./test/test

cppcheck:
	cppcheck *.c *.h tests/*.c tests/*.h

clean:
	-rm -rf *.o *.gcno *.gcda *.info  test s21_matrix.a gcov_report report greport a.out *.txt *.dSYM


