default: all

all: 

ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp catch.hpp
	g++ -o ArrayList_TEST ArrayList_TEST.cpp
	./ArrayList_TEST

testgcov_ArrayList_TEST: 
	g++ --coverage -o ArrayList_TEST ArrayList_TEST.cpp
	./ArrayList_TEST
	gcov ArrayList_TEST.cpp

testlcov_ArrayList_TEST: testgcov_ArrayList_TEST
	lcov --directory ./ --zerocounters
	./ArrayList_TEST
	lcov --directory ./ --capture --output-file ArrayList_TEST.info
	genhtml --output-directory coverage ArrayList_TEST.info



clean:
	rm -R *.o *.gcda *.info *.gcno *.gcov *.dSYM coverage ArrayList_TEST a.out
