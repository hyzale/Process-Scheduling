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
	./LinkedList_TEST
	gcov LinkedList_TEST.cpp

testlcov_LinkedList_TEST: testgcov_LinkedList_TEST
	lcov --directory ./ --zerocounters
	./LinkedList_TEST
	lcov --directory ./ --capture --output-file LinkedList_TEST.info
	genhtml --output-directory coverage LinkedList_TEST.info

BSTNode_TEST: BSTNode_TEST.cpp BSTNode.hpp BSTNode.tpp catch.hpp
	g++ -std=c++11 -o BSTNode_TEST BSTNode_TEST.cpp
	./BSTNode_TEST

testgcov_BSTNode_TEST: 
	g++ -std=c++11 --coverage -o BSTNode_TEST BSTNode_TEST.cpp
	./BSTNode_TEST
	gcov BSTNode_TEST.cpp

testlcov_BSTNode_TEST: testgcov_BSTNode_TEST
	lcov --directory ./ --zerocounters
	./BSTNode_TEST
	lcov --directory ./ --capture --output-file BSTNode_TEST.info
	genhtml --output-directory coverage BSTNode_TEST.info

BSTMultimap_TEST: BSTMultimap_TEST.cpp BSTMultimap.hpp BSTMultimap.tpp BSTNode.hpp BSTNode.tpp catch.hpp BSTForwardIterator.tpp  BSTForwardIterator.hpp
	g++ -std=c++11 -o BSTMultimap_TEST BSTMultimap_TEST.cpp
	./BSTMultimap_TEST

testgcov_BSTMultimap_TEST: 
	g++ -std=c++11 --coverage -o BSTMultimap_TEST BSTMultimap_TEST.cpp
	./BSTMultimap_TEST
	gcov BSTMultimap_TEST.cpp

testlcov_BSTMultimap_TEST: testgcov_BSTMultimap_TEST
	lcov --directory ./ --zerocounters
	./BSTMultimap_TEST
	lcov --directory ./ --capture --output-file BSTMultimap_TEST.info
	genhtml --output-directory coverage BSTMultimap_TEST.info

RBTNode_TEST: RBTNode_TEST.cpp RBTNode.hpp RBTNode.tpp catch.hpp
	g++ -std=c++11 -o RBTNode_TEST RBTNode_TEST.cpp
	./RBTNode_TEST

testgcov_RBTNode_TEST: 
	g++ -std=c++11 --coverage -o RBTNode_TEST RBTNode_TEST.cpp
	./RBTNode_TEST
	gcov RBTNode_TEST.cpp

testlcov_RBTNode_TEST: testgcov_RBTNode_TEST
	lcov --directory ./ --zerocounters
	./RBTNode_TEST
	lcov --directory ./ --capture --output-file RBTNode_TEST.info
	genhtml --output-directory coverage RBTNode_TEST.info

RBTMultimap_TEST: RBTMultimap_TEST.cpp RBTMultimap.hpp RBTMultimap.tpp RBTNode.hpp RBTNode.tpp catch.hpp BSTForwardIterator.tpp  BSTForwardIterator.hpp
	g++ -std=c++11 -o RBTMultimap_TEST RBTMultimap_TEST.cpp
	./RBTMultimap_TEST

testgcov_RBTMultimap_TEST: 
	g++ -std=c++11 --coverage -o RBTMultimap_TEST RBTMultimap_TEST.cpp
	./RBTMultimap_TEST
	gcov RBTMultimap_TEST.cpp

testlcov_RBTMultimap_TEST: testgcov_RBTMultimap_TEST
	lcov --directory ./ --zerocounters
	./RBTMultimap_TEST
	lcov --directory ./ --capture --output-file RBTMultimap_TEST.info
	genhtml --output-directory coverage RBTMultimap_TEST.info

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

run_simulator: Scheduler.hpp Process.hpp simulate.hpp Scheduler.cpp Process.cpp simulate.cpp 
	g++ schedulesim.cpp Scheduler.cpp Process.cpp simulate.cpp --std=c++11 -o simu
	./simu 1000 10 1000000



clean:
	rm -R *.o *.gcda *.info *.gcno *.gcov *.dSYM coverage ArrayList_TEST a.out LinkedList_TEST simu BSTNode_TEST BSTMultimap_TEST
