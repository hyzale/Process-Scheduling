#include <algorithm>

template <class item_t>
ArrayList<item_t>::ArrayList() {
    items = new item_t[10];
    size = 0;
    capacity = 10;
}

template <class item_t>
ArrayList<item_t>::ArrayList(int capacity) {
    items = new item_t[capacity];
    size = 0;
    this->capacity = capacity;
}

template <class item_t>
ArrayList<item_t>::~ArrayList() {
    delete items;
}

template <class item_t>
void ArrayList<item_t>::resize(int cap) {
    item_t* destination = new item_t[cap];
    std::copy_n(items, size, destination);
    delete items;
    items = destination;
    capacity = cap;
}

template <class item_t>
void ArrayList<item_t>::resizeIfFull() {
    if (size == capacity) {
        resize(size * 2);
    }
}

template <class item_t>
void ArrayList<item_t>::pushBack(const item_t& item) {
    resizeIfFull();
    items[size] = item;
    size++;
}

template <class item_t>
void ArrayList<item_t>::popBack() {
    size--;
}

template <class item_t>
const item_t& ArrayList<item_t>::getBack() const {
    return items[size - 1];
}

template <class item_t>
void ArrayList<item_t>::pushFront(const item_t& item) {
    insert(0, item);
}

template <class item_t>
void ArrayList<item_t>::popFront() {
    remove(0);
}

template <class item_t>
const item_t& ArrayList<item_t>::getFront() const {
    return items[0];
}

template <class item_t>
const item_t& ArrayList<item_t>::getItem(int index) const {
    return items[index];
}

template <class item_t>
void ArrayList<item_t>::setItem(int index, const item_t& item) {
    //NOT SURE HOW TO HANDLE INDEX NOT IN SIZE. 
    //Documentation not mentioned.
    if (index < 0 || index > size) {
        return;
    } else if (index == size) {
        pushBack(item);
    } else {
        items[index] = item;
    }
}

template <class item_t>
void ArrayList<item_t>::insert(int index, const item_t& item) {
    if (index < 0 || index > size) {
        return;
    }  else if (index == size) {
        pushBack(item);
    } else {
        resizeIfFull();
        for (int i = size + 1; i > index; i--) {
            items[i] = items[i - 1];
        }
        items[index] = item;
        size++;
    }
}

template <class item_t>
void ArrayList<item_t>::remove(int index) {
    for (int i = index; i < size; i++) {
        items[i] = items[i + 1];
    }
    size--;
}


template <class item_t>
int ArrayList<item_t>::getSize() const {
    return size;
}

template <class item_t>
bool ArrayList<item_t>::isEmpty() const {
    return size == 0 ? true : false;
}

template <class item_t>
int ArrayList<item_t>::getCapacity() const {
    return capacity;
}