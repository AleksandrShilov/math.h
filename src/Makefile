FLAGSO=-c -Wall -Werror -Wextra
CFLAGS2=-fprofile-arcs -ftest-coverage
LFLAGS=-lcheck -lm -pthread -lgcov --coverage

all: clean gcov_report s21_math.a

s21_math.a:
	gcc -c s21_math.c -o s21_math.o
	ar rc s21_math.a s21_math.o

gcov_report: test
	gcovr -r . --html --html-details -o gcov_report.html
	open gcov_report.html

test: s21_math_test.o test.o
	gcc $^ -o test.out $(LFLAGS) && ./test.out

test.o: test.c
	gcc $(FLAGSO) $(CFLAGS2) $^ -o $@

s21_math_test.o: s21_math.c
	gcc $(FLAGSO) $(CFLAGS2) $^ -o $@

check_python: s21_math.c s21_math.h
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c $^

check_valgrind:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test.out

check_leaks:
	CK_FORK=no leaks -atExit -- ./test.out

check_cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem s21_math.c test.c

clean:
	rm -rf *.o *.gch *.cfg *.out *html *.gcno *.gcda *.txt *.css *.a