#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

#include "BSTNode.hpp"

TEST_CASE ("Testing BSTNode") {

    SECTION ("Testing get and set key/value") {
        BSTNode<int, int>* a = new BSTNode<int, int>(5, 5);
        REQUIRE (a->getValue() == 5);
        REQUIRE (a->getKey() == 5);
        a->setValue(1);
        a->setKey(2);
        REQUIRE (a->getValue() == 1);
        REQUIRE (a->getKey() == 2);
        delete a;
    }

    SECTION ("Testing get and set children and parents") {
        BSTNode<int, int>* a = new BSTNode<int, int>(1, 1);
        BSTNode<int, int>* b = new BSTNode<int, int>(2, 2);
        BSTNode<int, int>* c = new BSTNode<int, int>(3, 3);
        a->setLeftChild(b);
        a->setRightChild(c);
        b->setParent(a);
        c->setParent(a);
        REQUIRE (a->getLeftChild() == b);
        REQUIRE (a->getRightChild() == c);
        REQUIRE (b->getParent() == a);
        REQUIRE (c->getParent() == a);
        delete a; delete b; delete c;
    }

}