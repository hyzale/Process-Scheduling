
template <class key_t, class val_t>
BSTNode<key_t, val_t>::BSTNode(const key_t& k, const val_t& v) {
    key = k;
    value = v;
    left = 0;
    right = 0;
    parent = 0;            
}

template <class key_t, class val_t>
const val_t& BSTNode<key_t, val_t>::getValue() const {
    return value;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setValue(const val_t newValue) {
    value = newValue;
}

template <class key_t, class val_t>
const key_t& BSTNode<key_t, val_t>::getKey() const {
    return key;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setKey(const key_t newKey) {
    key = newKey;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getLeftChild() const {
    return left;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setLeftChild(BSTNode<key_t, val_t>* newLeft) {
    left = newLeft;
}


template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getRightChild() const {
    return right;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setRightChild(BSTNode<key_t, val_t>* newRight) {
    right = newRight;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getParent() const {
    return parent;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setParent(BSTNode<key_t, val_t>* newParent) {
    parent = newParent;
}

template <class key_t, class val_t>
string BSTNode<key_t, val_t>::inOrder() {
    string res;
    if (left) {
        res += left->inOrder() + ' ';
    }
    res += to_string(key) + ' ';
    if (right) {
        res += right->inOrder() + ' ';
    }
    return res;
}

