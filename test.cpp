#include <iostream>

#include "LinkedList.hpp"
#include "LinkedListNode.hpp"

using namespace std;


int main()
{
    LinkedList<int> a;
    a.popBack();

    cout << (a.isEmpty()) << endl;
    a.pushBack(5);
    a.pushBack(4);
    cout << (a.getBack()) << endl;
    cout << (a.isEmpty()) << endl;
    a.popBack();
    cout << (a.isEmpty()) << endl;
    a.popBack();
    cout << (a.isEmpty()) << endl;


}