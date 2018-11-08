#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

#include "RBTNode.hpp"

TEST_CASE ("Testing RBTNode") {

    SECTION ("Testing get and set key/value") {
        RBTNode<int, int>* a = new RBTNode<int, int>(5, 5, false);
        REQUIRE (a->getValue() == 5);
        REQUIRE (a->getKey() == 5);
        a->setValue(1);
        a->setKey(2);
        REQUIRE (a->getValue() == 1);
        REQUIRE (a->getKey() == 2);
        delete a;
    }

    SECTION ("Testing get and set children and parents") {
        RBTNode<int, int>* a = new RBTNode<int, int>(1, 1, false);
        RBTNode<int, int>* b = new RBTNode<int, int>(2, 2, false);
        RBTNode<int, int>* c = new RBTNode<int, int>(3, 3, false);
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