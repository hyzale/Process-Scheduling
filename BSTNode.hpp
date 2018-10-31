#ifndef BSTNODE
#define BSTNODE


template <class key_t, class val_t>
class BSTNode 
{
  private:
   key_t key;
   val_t value;
   BSTNode<key_t, val_t>* left;
   BSTNode<key_t, val_t>* right;

  public:
   BSTNode(key_t k, val_t v);
   





};



#include "BSTNode.hpp"

#endif