default: all

all: 

ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp catch.hpp
	g++ -o ArrayList_TEST ArrayList_TEST.cpp
	./ArrayList_TEST


clean:
	rm -R *.o *.gcda *.info *.gcno *.gcov *.dSYM ArrayList_TEST
	