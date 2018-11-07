

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t>::BSTForwardIterator(BSTNode<key_t, val_t>* node, BSTNode<key_t, val_t>* sentinel){
    current = node;
    this->sentinel = sentinel;
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::next() {
    if (current == sentinel) {
        return;
    }
    if (current->getRightChild() != sentinel)  {
        current = current->getRightChild();
        while (current->getLeftChild() != sentinel) {
            current = current->getLeftChild();
        }
        return;
    }
    BSTNode<key_t, val_t>* traveler = current->getParent();
    while (traveler != sentinel && current == traveler->getRightChild()) {
        current = traveler;
        traveler = traveler->getParent();
    }
    current = traveler;
}

template <class key_t, class val_t>
bool BSTForwardIterator<key_t, val_t>::isPastEnd() const {
    return current == sentinel;
}

template <class key_t, class val_t>
const key_t& BSTForwardIterator<key_t, val_t>::getKey() const {
    return current->getKey();
}

template <class key_t, class val_t>
const val_t& BSTForwardIterator<key_t, val_t>::getValue() const {
    return current->getValue();
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::setValue(const val_t& newVal) {
    current->setValue(newVal);
}