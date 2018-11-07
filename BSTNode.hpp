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
   BSTNode<key_t, val_t>* parent;

  public:
   BSTNode(const key_t& k, const val_t& v);

   const val_t& getValue() const;
   void setValue(const val_t newValue);

   const key_t& getKey() const;
   void setKey(const key_t newKey);

   BSTNode<key_t, val_t>* getLeftChild() const;
   void setLeftChild(BSTNode<key_t, val_t>* newLeft);

   BSTNode<key_t, val_t>* getRightChild() const;
   void setRightChild(BSTNode<key_t, val_t>* newRight);

   BSTNode<key_t, val_t>* getParent() const;
   void setParent(BSTNode<key_t, val_t>* newParent);

};

#include "BSTNode.tpp"

#endif