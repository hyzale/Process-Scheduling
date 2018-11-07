#include <iostream>

#include "LinkedList.hpp"
#include "LinkedListNode.hpp"
#include "ArrayList.hpp"
#include "BSTNode.hpp"
#include "BSTMultimap.hpp"

using namespace std;

int main()
{
    BSTMultimap<int, int>* a = new BSTMultimap<int, int>();
    a->insert(5, 5);
    // a->insert(2, 2);
    // a->insert(2, 2);
    // a->insert(3, 3);
    // a->insert(4, 4);
    // cout << a->toString() << endl;
    // a->insert(1, 1);
    // a->insert(6, 6);
    // a->insert(7, 7);
    // a->insert(8, 8);
    // a->insert(9, 9);
    cout << a->toString() << endl;
}