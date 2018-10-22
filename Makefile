default: all

all: 



ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp catch.hpp ArrayList.tpp
	g++ -std=c++11 -o ArrayList_TEST ArrayList_TEST.cpp 
	./ArrayList_TEST


LinkedList_TEST: LinkedList_TEST.cpp LinkedListNode.hpp LinkedList.hpp catch.hpp LinkedList.tpp
	g++ -std=c++11 -o LinkedList_TEST LinkedList_TEST.cpp
	./LinkedList_TEST 

testgcov_ArrayList_TEST: 
	g++ -std=c++11 --coverage -o ArrayList_TEST ArrayList_TEST.cpp
	./ArrayList_TEST
	gcov ArrayList_TEST.cpp

testlcov_ArrayList_TEST: testgcov_ArrayList_TEST
	lcov --directory ./ --zerocounters
	./ArrayList_TEST
	lcov --directory ./ --capture --output-file ArrayList_TEST.info
	genhtml --output-directory coverage ArrayList_TEST.info

tests: ArrayList_TEST
	./ArrayList_TEST




clean:
	rm -R *.o *.gcda *.info *.gcno *.gcov *.dSYM coverage ArrayList_TEST a.out LinkedList_TEST
