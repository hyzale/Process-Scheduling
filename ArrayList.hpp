#ifndef ARRAY_LIST
#define ARRAY_LIST

template <class item_t>
class ArrayList
{
  private:
   item_t* items;
   int size;
   int capacity;
   
  public:
   //Creates an empty list with capacity 10
   ArrayList();
   //Creates a list with the given capacity
   ArrayList(int capacity);
   ~ArrayList();

   //Pushes item to the back of the list
   void pushBack(const item_t& item);   
   //Removes, but does not return, the last item
   void popBack();
   //Returns a reference to the last item (does not remove it).
   const item_t& getBack() const;
   
   //Pushes item to the front of the list
   void pushFront(const item_t& item);
   //Removes, but does not return, the first item
   void popFront();
   //Returns a reference to the first item (does not remove it).
   const item_t& getFront() const;

   //Returns a reference to the item at the given index
   const item_t& getItem(int index) const;
   //Sets the item at the given index
   void setItem(int index, const item_t& item);

   //Inserts the given item at the given index
   //(items at index or beyond shift up one position)
   //Inserting just past the last element (i.e. position
   //size) shoud be equivalent to pushBack.
   void insert(int index, const item_t& item);
   //Removes the item at the given index
   //(items beyond index shift down one position)
   void remove(int index);

   //Returns the number of items in the list
   int getSize() const;
   //Returns true if the list is empty (false otherwise)
   bool isEmpty() const;
   //Returns the size of the array that contains the list
   int getCapacity() const;
};

#include "ArrayList.tpp"

#endif
