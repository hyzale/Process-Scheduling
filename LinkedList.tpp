

template <class item_t>
LinkedList<item_t>::LinkedList() {
    head = 0;
    tail = 0;
    size = 0;
}

template <class item_t>
LinkedList<item_t>::~LinkedList() {
    LinkedListNode<item_t>* traveler = head;
    while (traveler != 0) {
        LinkedListNode<item_t>* next = traveler->getNext();
        delete traveler;
        traveler = next;
    }
}

template <class item_t>
void LinkedList<item_t>::pushBack(const item_t& item) {
    LinkedListNode<item_t>* newNode = new LinkedListNode<item_t>(0, item);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
    size++;
}

template <class item_t>
void LinkedList<item_t>::popBack() {
    if (isEmpty()) {
        return;
    }
    LinkedListNode<item_t>* traveler = head;
    while (traveler->getNext() != tail) {
        traveler = traveler->getNext();
    }
    delete tail;
    tail = traveler;
    size--;

}

template <class item_t>
const item_t& LinkedList<item_t>::getFront() const {
    return head->getItem();
}

template <class item_t>
const item_t& LinkedList<item_t>::getItem(int index) const {
    LinkedListNode<item_t>* traveler = head;
    while (index > 0) {
        traveler = traveler->getNext();
        index--;
    }
    return traveler->getItem();
}

template <class item_t>
void LinkedList<item_t>::setItem(int index, const item_t& item) {
    LinkedListNode<item_t>* traveler = head;
    while (index > 0) {
        traveler = traveler->getNext();
        index--;
    }
    traveler->setItem(item);
}

template <class item_t>
void LinkedList<item_t>::insert(int index, const item_t& item) {
    LinkedListNode<item_t>* before = head;
    while (index > 1) {
        before = before->getNext();
        index--;
    }
    LinkedListNode<item_t>* after = before->getNext();
    LinkedListNode<item_t>* newNode = new LinkedListNode<item_t>(after, item);
    before->setNext(newNode);
    size++;
}

template <class item_t>
void LinkedList<item_t>::remove(int index) {
    LinkedListNode<item_t>* before = head;
    while (index > 1) {
        before = before->getNext();
        index--;
    }
    LinkedListNode<item_t>* del = before->getNext();
    LinkedListNode<item_t>* after = del->getNext();
    delete del;
    before->setNext(after);
    size--;

}

template <class item_t>
LinkedList<item_t>::getSize() const {
    return size;
}

template <class item_t>
LinkedList<item_t>::isEmpty() const {
    head == 0 ? true : false;
}