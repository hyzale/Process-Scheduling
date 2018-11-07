default: all

all: 



ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp catch.hpp ArrayList.tpp
	g++ -std=c++11 -o ArrayList_TEST ArrayList_TEST.cpp 
	./ArrayList_TEST

testgcov_ArrayList_TEST: 
	g++ -std=c++11 --coverage -o ArrayList_TEST ArrayList_TEST.cpp
	./ArrayList_TEST
	gcov ArrayList_TEST.cpp

testlcov_ArrayList_TEST: testgcov_ArrayList_TEST
	lcov --directory ./ --zerocounters
	./ArrayList_TEST
	lcov --directory ./ --capture --output-file ArrayList_TEST.info
	genhtml --output-directory coverage ArrayList_TEST.info

LinkedList_TEST: LinkedList_TEST.cpp LinkedListNode.hpp LinkedList.hpp catch.hpp LinkedList.tpp
	g++ -std=c++11 -o LinkedList_TEST LinkedList_TEST.cpp
	./LinkedList_TEST 

testgcov_LinkedList_TEST: 
	g++ -std=c++11 --coverage -o LinkedList_TEST LinkedList_TEST.cpp
	./ArrayList_TEST
	gcov LinkedList_TEST.cpp

testlcov_LinkedList_TEST: testgcov_LinkedList_TEST
	lcov --directory ./ --zerocounters
	./LinkedList_TEST
	lcov --directory ./ --capture --output-file LinkedList_TEST.info
	genhtml --output-directory coverage LinkedList_TEST.info

tests: ArrayList_TEST
	./ArrayList_TEST

run_simulator_jieguo: Scheduler.hpp Process.hpp simulate.hpp Scheduler.cpp Process.cpp simulate.cpp 
	g++ schedulesim.cpp Scheduler.cpp Process.cpp simulate.cpp --std=c++11 -o simu	
	./simu 1000 10 1000000
	./simu 2000 10 1000000
	./simu 3000 10 1000000
	./simu 4000 10 1000000
	./simu 5000 10 1000000
	./simu 6000 10 1000000
	./simu 7000 10 1000000
	./simu 8000 10 1000000
	./simu 9000 10 1000000
	./simu 10000 10 1000000
	rm simu

run_simulator: Scheduler.hpp Process.hpp simulate.hpp Scheduler.cpp Process.cpp simulate.cpp 
	g++ schedulesim.cpp Scheduler.cpp Process.cpp simulate.cpp --std=c++11 -o simu
	./simu 1000 10 1000000



clean:
	rm -R *.o *.gcda *.info *.gcno *.gcov *.dSYM coverage ArrayList_TEST a.out LinkedList_TEST
