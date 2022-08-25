FLAGSO=-c -Wall -Werror -Wextra
CFLAGS2=-fprofile-arcs -ftest-coverage
LFLAGS=-lcheck -lm -pthread -lgcov --coverage

all: clean gcov_report my_math.a

my_math.a:
	gcc -c my_math.c -o my_math.o
	ar rc my_math.a my_math.o

gcov_report: test
	gcovr -r . --html --html-details -o gcov_report.html
	open gcov_report.html

test: my_math_test.o test.o
	gcc $^ -o test.out $(LFLAGS) && ./test.out

test.o: test.c
	gcc $(FLAGSO) $(CFLAGS2) $^ -o $@

my_math_test.o: my_math.c
	gcc $(FLAGSO) $(CFLAGS2) $^ -o $@

check_python: my_math.c my_math.h
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c $^

check_valgrind:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test.out

check_leaks:
	CK_FORK=no leaks -atExit -- ./test.out

check_cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem my_math.c test.c

clean:
	rm -rf *.o *.gch *.cfg *.out *html *.gcno *.gcda *.txt *.css *.a