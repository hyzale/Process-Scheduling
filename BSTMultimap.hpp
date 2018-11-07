#ifndef BSTMULTIMAP
#define BSTMULTIMAP

#include "BSTNode.hpp"
#include "BSTForwardIterator.hpp"

#include <string>

using namespace std;

template <class key_t, class val_t>
class BSTMultimap
{
  protected:

   BSTNode<key_t, val_t>* root;
   BSTNode<key_t, val_t>* sentinel;
   int numItems;
   void insertNode(BSTNode<key_t, val_t>* newNode);
   void transplant(BSTNode<key_t,val_t>* del, BSTNode<key_t,val_t>* child, BSTNode<key_t,val_t>* parent);

  public:
   BSTMultimap();
   virtual ~BSTMultimap();

   void clear(BSTNode<key_t, val_t>* node);
   virtual void insert(const key_t& key, const val_t& val);
   virtual int getSize() const;
   virtual bool isEmpty() const;
   virtual string toString() const;
   virtual bool contains(const key_t& key) const;
   virtual void clear();

   virtual BSTForwardIterator<key_t, val_t> getMin() const;
   virtual BSTForwardIterator<key_t, val_t> getMax() const;
   virtual BSTForwardIterator<key_t, val_t> findFirst(const key_t& key) const;
   virtual BSTForwardIterator<key_t, val_t> findLast(const key_t& key) const;
   virtual BSTForwardIterator<key_t, val_t> remove(const BSTForwardIterator<key_t, val_t>& pos);
};

#include "BSTMultimap.tpp"


#endif