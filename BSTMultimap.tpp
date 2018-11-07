

template <class key_t, class val_t>
BSTMultimap<key_t, val_t>::BSTMultimap(){
    sentinel = 0;
    root = sentinel;
    numItems = 0;
}

//Insert node if key is not in BST already.
template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& val) {
    if (root == 0) {
        root = new BSTNode<key_t, val_t>(key, val);
        root->setLeftChild(sentinel);
        root->setRightChild(sentinel);
        root->setParent(sentinel);
    } else {
        BSTNode<key_t, val_t>* traveler = root;
        while (traveler->getKey() != key) {
            if (traveler->getKey() > key) {
                if (traveler->getLeftChild() == sentinel) {
                    BSTNode<key_t, val_t>* newNode = new BSTNode<key_t, val_t>(key, val);
                    traveler->setLeftChild(newNode);
                    newNode->setLeftChild(sentinel);
                    newNode->setRightChild(sentinel);
                    newNode->setParent(traveler);
                }
                traveler = traveler->getLeftChild();
            }
            if (traveler->getKey() < key) {
                if (traveler->getRightChild() == sentinel) {
                    BSTNode<key_t, val_t>* newNode = new BSTNode<key_t, val_t>(key, val);
                    traveler->setRightChild(newNode);
                    newNode->setRightChild(sentinel);
                    newNode->setLeftChild(sentinel);
                    newNode->setParent(traveler);
                }
                traveler = traveler->getRightChild();
            }
        }
    }
}

template <class key_t, class val_t>
int BSTMultimap<key_t, val_t>::getSize() {
    return numItems;
}

template <class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::isEmpty() {
    return numItems == 0;

}

template <class key_t, class val_t>
string BSTMultimap<key_t, val_t>::toString() {
    if (root){
        return root->toString();
    }
    return "";
}

