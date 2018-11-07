#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

#include "BSTMultimap.hpp"
#include "BSTForwardIterator.hpp"

using namespace std;

TEST_CASE ("Testing BSTNode") {
    
    SECTION ("Testing insert, getSize, contains") {
        BSTMultimap<int, int>* a = new BSTMultimap<int, int>();
        REQUIRE(a->contains(2) == false);
        REQUIRE(a->isEmpty() == true);
        a->insert(5, 5);
        a->insert(8, 8);
        a->insert(9, 9);
        a->insert(2, 2);
        a->insert(2, 3);
        a->insert(6, 6);
        a->insert(7, 7);
        a->insert(3, 3);
        a->insert(4, 4);
        a->insert(1, 1);
        REQUIRE(a->isEmpty() == false);
        REQUIRE(a->getSize() == 10);
        REQUIRE(a->contains(2) == true);
        REQUIRE(a->contains(10) == false);
        a->clear();
        REQUIRE(a->isEmpty() == true);
        a->clear();
        REQUIRE(a->isEmpty() == true);
        delete a;
    }

    SECTION ("Testing getMin, getMax") {
        BSTMultimap<int, int>* a = new BSTMultimap<int, int>();
        BSTForwardIterator<int, int> b = a->getMin();
        BSTForwardIterator<int, int> c = a->getMax();
        a->insert(5, 5);
        a->insert(8, 8);
        a->insert(9, 9);
        a->insert(2, 2);
        a->insert(2, 345);
        a->insert(6, 6);
        a->insert(7, 7);
        a->insert(3, 3);
        a->insert(4, 4);
        a->insert(1, 233);
        b = a->getMin();
        REQUIRE(b.getKey() == 1);
        REQUIRE(a->getSize() == 10);
        REQUIRE(b.getValue() == 233);
        b.setValue(1);
        REQUIRE(b.getValue() == 1);
        REQUIRE(b.getKey() == 1);
        b.next();
        REQUIRE(b.getValue() == 345);
        b.next();
        REQUIRE(b.getValue() == 2);
        b.next();
        REQUIRE(b.getKey() == 3);
        b.next();
        REQUIRE(b.getKey() == 4);
        b.next();
        REQUIRE(b.getKey() == 5);
        b.next();
        REQUIRE(b.getKey() == 6);
        c = a->getMax();
        REQUIRE(c.getKey() == 9);
        REQUIRE(c.getValue() == 9);
        REQUIRE(c.isPastEnd() == false);
        c.next();
        REQUIRE(c.isPastEnd() == true);
        c.next();
        REQUIRE(c.isPastEnd() == true);
        delete a;
    }

    SECTION ("Testing findfirst findlast") {
        BSTMultimap<int, int>* a = new BSTMultimap<int, int>();
        a->insert(5, 5);
        a->insert(8, 8);
        a->insert(9, 9);
        a->insert(2, 22222);
        a->insert(2, 2222);
        a->insert(2, 222);
        a->insert(2, 22);
        a->insert(2, 2);
        a->insert(6, 6);
        a->insert(7, 7);
        a->insert(3, 3);
        a->insert(4, 4);
        a->insert(1, 1);
        BSTForwardIterator<int, int> b = a->findFirst(2);
        REQUIRE(b.getValue() == 2);
        BSTForwardIterator<int, int> c = a->findLast(2);
        REQUIRE(c.getValue() == 22222);
        BSTForwardIterator<int, int> d = a->findFirst(788);
        REQUIRE(d.isPastEnd() == true);
        BSTForwardIterator<int, int> e = a->findLast(788);
        REQUIRE(e.isPastEnd() == true);
        delete a;
    }

    SECTION ("Testing remove") {
        BSTMultimap<int, int>* a = new BSTMultimap<int, int>();
        BSTForwardIterator<int, int> b = a->getMin();
        a->insert(5, 5);
        b = a->getMin();
        REQUIRE(b.getValue() == 5);
        a->remove(b);
        a->insert(5, 5);
        a->insert(8, 8);
        a->insert(9, 9);
        a->insert(2, 2);
        a->insert(6, 6);
        a->insert(7, 7);
        a->insert(3, 3);
        a->insert(4, 4);
        a->insert(1, 1);
        b = a->getMin();
        REQUIRE(b.getKey() == 1);
        b = a->getMin();
        REQUIRE(a->getSize() == 9);
        REQUIRE(a->remove(b).getKey() == 2);
        b = a->getMin();
        REQUIRE(b.getKey() == 2);
        REQUIRE(a->getSize() == 8);
        a->remove(b);
        b = a->getMin();
        REQUIRE(b.getKey() == 3);
        REQUIRE(a->getSize() == 7);

        delete a;

    }

}
