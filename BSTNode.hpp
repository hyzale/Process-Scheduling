#ifndef BSTNODE
#define BSTNODE

#include <string>

using namespace std;



template <class key_t, class val_t>
class BSTNode 
{
  private:
   key_t key;
   val_t value;
   BSTNode<key_t, val_t>* left;
   BSTNode<key_t, val_t>* right;
   BSTNode<key_t, val_t>* parent;

  public:
   BSTNode(const key_t& k, const val_t& v);

   virtual const val_t& getValue() const;
   virtual void setValue(const val_t newValue);

   virtual const key_t& getKey() const;
   virtual void setKey(const key_t newKey);

   virtual BSTNode<key_t, val_t>* getLeftChild() const;
   virtual void setLeftChild(BSTNode<key_t, val_t>* newLeft);

   virtual BSTNode<key_t, val_t>* getRightChild() const;
   virtual void setRightChild(BSTNode<key_t, val_t>* newRight);

   virtual BSTNode<key_t, val_t>* getParent() const;
   virtual void setParent(BSTNode<key_t, val_t>* newParent);

   virtual string inOrder();
};

#include "BSTNode.tpp"

#endif