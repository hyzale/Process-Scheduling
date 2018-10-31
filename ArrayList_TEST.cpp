#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ArrayList.hpp"


TEST_CASE ("Testing ArrayList") {


    SECTION ("Testing pushBack, popBack, and getBack") {
        ArrayList<int>* a = new ArrayList<int>();
        a->pushBack(5);
        a->pushBack(4);
        REQUIRE (a->getSize() == 2);
        REQUIRE (a->getCapacity() == 10);
        REQUIRE (a->isEmpty() == false);
        REQUIRE (a->getBack() == 4);
        a->popBack();
        a->popBack();
        REQUIRE (a->getSize() == 0);
        REQUIRE (a->getCapacity() == 10);
        REQUIRE (a->isEmpty() == true);
        delete a;
    }
    
    SECTION ("Testing pushFront, popFront and getFront") {
        ArrayList<int>* a = new ArrayList<int>(3);
        a->pushFront(5);
        a->pushFront(4);
        a->pushFront(3);
        a->pushFront(2);
        a->pushFront(1);
        a->pushFront(0);
        REQUIRE (a->getSize() == 6);
        REQUIRE (a->getCapacity() == 6);
        REQUIRE (a->isEmpty() == false);
        REQUIRE (a->getFront() == 0);
        a->popFront();
        REQUIRE (a->getSize() == 5);
        REQUIRE (a->getCapacity() == 6);
        REQUIRE (a->getFront() == 1);
        a->popFront();
        a->popFront();
        a->popFront();
        a->popFront();
        a->popFront();
        REQUIRE (a->isEmpty() == true);
        delete a;
    }

    SECTION ("Testing getItem and setItem") {
        ArrayList<int>* a = new ArrayList<int>();
        a->setItem(0, 788);
        a->setItem(1, 2);
        a->setItem(2, 3);
        REQUIRE (a->getItem(0) == 788);
        REQUIRE (a->getItem(1) == 2);
        REQUIRE (a->getItem(2) == 3);
        a->setItem(0, 1);
        REQUIRE (a->getItem(0) == 1);
        delete a;
    }
    SECTION ("Testing insert and remove") {
        ArrayList<int>* a = new ArrayList<int>();
        a->insert(0, 1);
        a->insert(1, 2);
        a->insert(2, 3);
        a->insert(3, 4);
        a->insert(4, 5);
        a->insert(0, 788);
        REQUIRE (a->getSize() == 6);
        REQUIRE (a->getItem(0) == 788);
        REQUIRE (a->getItem(1) == 1);
        a->remove(3);
        REQUIRE (a->getItem(3) == 4);
        delete a;
    }

}
