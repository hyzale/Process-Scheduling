

template <class key_t, class val_t>
BSTMultimap<key_t, val_t>::BSTMultimap(){
    sentinel = 0;
    root = sentinel;
    numItems = 0;
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& val) {
    BSTNode<key_t, val_t>* newNode = new BSTNode<key_t, val_t>(key, val);
    insertNode(newNode);
    numItems++;
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insertNode(BSTNode<key_t, val_t>* newNode) {
    BSTNode<key_t, val_t>* traveler = root;
    BSTNode<key_t, val_t>* newParent = sentinel;
    while (traveler != sentinel) {
        newParent = traveler;
        if (newNode->getKey() < traveler->getKey()) {
          traveler = traveler->getLeftChild();
        } else {
          traveler = traveler->getRightChild();
        }
    }
    newNode->setParent(newParent);
    if (isEmpty()) {
        root = newNode;
    }
    else if (newNode->getKey() <= newParent->getKey()) {
      newParent->setLeftChild(newNode);
    } else {
      newParent->setRightChild(newNode);
    }
}

template <class key_t, class val_t>
int BSTMultimap<key_t, val_t>::getSize() const {
    return numItems;
}

template <class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::isEmpty() const {
    return numItems == 0;

}

template <class key_t, class val_t>
string BSTMultimap<key_t, val_t>::toString() const {
    if (root != sentinel) {
        return root->inOrder();
    }
    return "";
}

template <class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::contains(const key_t& key) const {
    if (isEmpty()) {
        return false;
    }
    BSTNode<key_t, val_t>* traveler = root;
    while (traveler != sentinel && key != traveler->getKey()) {
        traveler = (key > traveler->getKey()) ? traveler->getRightChild() : traveler->getLeftChild();
    }
    return traveler != sentinel && key == traveler->getKey();
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::clear() {
    clear(root);
    root = sentinel;
    numItems = 0;
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::clear(BSTNode<key_t, val_t>* node) {
    if (node == sentinel) {
        return;
    }
    if (node->getLeftChild()) {
        clear(node->getLeftChild());
    }
    if (node->getRightChild()) {
        clear(node->getRightChild());
    }
    delete node;
    return;
}

template <class key_t, class val_t>
BSTMultimap<key_t, val_t>::~BSTMultimap() {
    clear();
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMin() const {
    if (isEmpty()) {
        return BSTForwardIterator<key_t, val_t>(this->sentinel, this->sentinel);
    }
    BSTNode<key_t, val_t>* traveler = root;
    while (traveler->getLeftChild() != sentinel) {
        traveler = traveler->getLeftChild();
    }
    return BSTForwardIterator<key_t, val_t>(traveler, this->sentinel);
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMax() const {
    if (isEmpty()) {
        return BSTForwardIterator<key_t, val_t>(sentinel, sentinel);
    }
    BSTNode<key_t, val_t>* traveler = root;
    while (traveler != sentinel && traveler->getRightChild() != sentinel) {
        traveler = traveler->getRightChild();
    }
    return BSTForwardIterator<key_t, val_t>(traveler, sentinel);
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>:: findFirst(const key_t& key) const {
    BSTNode<key_t, val_t>* traveler = root;
    while (traveler != sentinel && traveler->getKey() != key){
        traveler = (traveler->getKey() > key) ? traveler->getLeftChild() : traveler->getRightChild();
    }
    if (traveler == sentinel) {
        return BSTForwardIterator<key_t, val_t>(traveler, sentinel);
    }
    while (traveler->getLeftChild() != sentinel && traveler->getLeftChild()->getKey() == key) {
        traveler = traveler->getLeftChild();
    }
    return BSTForwardIterator<key_t, val_t>(traveler, sentinel);

}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>:: findLast(const key_t& key) const {
    BSTNode<key_t, val_t>* traveler = root;
    while (traveler != sentinel && traveler->getKey() != key){
        traveler = (traveler->getKey() > key) ? traveler->getLeftChild() : traveler->getRightChild();
    }
    if (traveler == sentinel) {
        return BSTForwardIterator<key_t, val_t>(traveler, sentinel);
    }
    return BSTForwardIterator<key_t, val_t>(traveler, sentinel);

}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos) {
    BSTNode<key_t,val_t>* deleteNode = pos.current;
    BSTNode<key_t,val_t>* leftChild = deleteNode->getLeftChild();
    BSTNode<key_t,val_t>* rightChild = deleteNode->getRightChild();
    BSTNode<key_t,val_t>* dad = deleteNode->getParent();
    BSTForwardIterator<key_t,val_t> successor = pos;
    successor.next();
    BSTNode<key_t,val_t>* nextNode = successor.current;
    if (deleteNode->getLeftChild() == sentinel) {
        transplant(deleteNode,rightChild,dad);
    } else if (deleteNode->getRightChild() == sentinel) {
        transplant(deleteNode,leftChild,dad);
    } else {
        if (nextNode->getParent() != deleteNode) {
            transplant(nextNode,nextNode->getRightChild(),nextNode->getParent());
            nextNode->setRightChild(rightChild);
            rightChild->setParent(nextNode);
        }
        transplant(deleteNode,nextNode,dad);
        nextNode->setLeftChild(leftChild);
        leftChild->setParent(nextNode);
    }
    numItems--;
    return successor; 
}




template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::transplant(BSTNode<key_t,val_t>* delNode, BSTNode<key_t,val_t>* childNode, BSTNode<key_t,val_t>* parentNode){
    if (parentNode == sentinel) {
        root = childNode;
    } else if (delNode == parentNode->getLeftChild()) {
        parentNode->setLeftChild(childNode);
    } else {
        parentNode->setRightChild(childNode);
    }
    if (childNode != sentinel) {
        childNode->setParent(parentNode);
    }
}






