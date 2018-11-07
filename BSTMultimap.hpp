#ifndef BSTMULTIMAP
#define BSTMULTIMAP

#include "BSTNode.hpp"
#include <string>

using namespace std;

template <class key_t, class val_t>
class BSTMultimap
{
  protected:
   BSTNode<key_t, val_t>* root;
   BSTNode<key_t, val_t>* sentinel;
   int numItems;


  public:
   BSTMultimap();

   void insert(const key_t& key, const val_t& val);
   int getSize();
   bool isEmpty();
   string toString();

};

#include "BSTMultimap.tpp"


#endif