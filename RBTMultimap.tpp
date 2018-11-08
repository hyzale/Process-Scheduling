
template <class key_t, class val_t>
RBTMultimap<key_t,val_t>::RBTMultimap() : BSTMultimap<key_t, val_t>() {
    key_t key; val_t val;
    RBTNode<key_t,val_t>* newNode = new RBTNode<key_t, val_t>(key, val, false);
    this->sentinel = newNode;
    this->root = this->sentinel;
}

template <class key_t, class val_t>
RBTMultimap<key_t,val_t>::~RBTMultimap() {
    this->clear();
	delete this->sentinel;
}


template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& value) {
    RBTNode<key_t, val_t>* newNode = new RBTNode<key_t, val_t>(key,value,true);
    newNode->setLeftChild(this->sentinel);
    newNode->setRightChild(this->sentinel);
    newNode->setParent(this->sentinel);
    this->insertNode(newNode);
    insertFixup(newNode);
}

template <class key_t, class val_t>
void RBTMultimap<key_t,val_t>::rotateLeft(BSTNode<key_t, val_t>* node) {
    BSTNode<key_t, val_t>* parentNode = node->getParent();
    BSTNode<key_t, val_t>* rotated = node->getRightChild();
    BSTNode<key_t, val_t>* rightLeft = rotated->getLeftChild();
    node->setRightChild(rightLeft);
    if (rightLeft != this->sentinel) { 
        rightLeft->setParent(node);
    }
    rotated->setParent(parentNode);
    if (parentNode == this->sentinel) {
        this->root = rotated;
    } else if (node == parentNode->getLeftChild()) {
        parentNode->setLeftChild(rotated);
    } else {
        parentNode->setRightChild(rotated);
    }
    rotated->setLeftChild(node);
    node->setParent(rotated);
}

template <class key_t, class val_t>   
void RBTMultimap<key_t,val_t>::rotateRight(BSTNode<key_t, val_t>* node) {
    BSTNode<key_t, val_t>* parentNode = node->getParent();
    BSTNode<key_t, val_t>* rotated = node->getLeftChild();
    BSTNode<key_t, val_t>* leftRight = rotated->getRightChild();
    node->setLeftChild(leftRight);
    if (leftRight != this->sentinel) {
        leftRight->setParent(node);
    }
    rotated->setParent(parentNode);
    if (parentNode == this->sentinel) {
        this->root = rotated;
    }
    else if (node == parentNode->getLeftChild()) {
        parentNode->setLeftChild(rotated);
    } else {
        parentNode->setRightChild(rotated);
    }
    rotated->setRightChild(node);
    node->setParent(rotated);
}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insertFixup(RBTNode<key_t, val_t>* insertedNode) {
    RBTNode<key_t, val_t>* niba;
    while (insertedNode->getParent()->isRed()) {
        if (insertedNode->getParent() == insertedNode->getParent()->getParent()->getLeftChild()) {
            niba = insertedNode->getParent()->getParent()->getRightChild();
            if (niba->isRed()) {
                insertedNode->getParent()->setIsRed(false);
                niba->setIsRed(false);
                insertedNode->getParent()->getParent()->setIsRed(true);
                insertedNode = insertedNode->getParent()->getParent();
            } else { 
                if (insertedNode ==insertedNode->getParent()->getRightChild()) {
                    insertedNode = insertedNode->getParent();
                    rotateLeft(insertedNode);
                }
                insertedNode->getParent()->setIsRed(false);
                insertedNode->getParent()->getParent()->setIsRed(true);
                rotateRight(insertedNode->getParent()->getParent());
            }
        } else {
            niba = insertedNode->getParent()->getParent()->getLeftChild();
            if (niba->isRed()) {
                insertedNode->getParent()->setIsRed(false);
                niba->setIsRed(false);
                insertedNode->getParent()->getParent()->setIsRed(true);
                insertedNode = insertedNode->getParent()->getParent();
            } else {
                if (insertedNode == insertedNode->getParent()->getLeftChild()) {
                    insertedNode = insertedNode->getParent();
                    rotateRight(insertedNode);
                }
                insertedNode->getParent()->setIsRed(false);
                insertedNode->getParent()->getParent()->setIsRed(true);
                rotateLeft(insertedNode->getParent()->getParent());
            }
        }
    }
    RBTNode<key_t, val_t>* newRoot = dynamic_cast<RBTNode<key_t, val_t>*>(this->root);
    newRoot->setIsRed(false);
}



template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::transplant(BSTNode<key_t, val_t>* nodeToReplace, BSTNode<key_t, val_t>* replacementNode) {
    if (nodeToReplace->getParent() == this->sentinel) {
        this->root = replacementNode;
    } else if (nodeToReplace == nodeToReplace->getParent()->getLeftChild()) {
        nodeToReplace->getParent()->setLeftChild(replacementNode);
    } else {
        nodeToReplace->getParent()->setRightChild(replacementNode);
    }
    replacementNode->setParent(nodeToReplace->getParent());
}


template <class key_t, class val_t>   
BSTForwardIterator<key_t, val_t> RBTMultimap<key_t,val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos) {
    BSTNode<key_t,val_t>* shanchu = pos.current;
    RBTNode<key_t,val_t>* shanchuRBT = dynamic_cast<RBTNode<key_t, val_t>* >(shanchu);
    BSTNode<key_t,val_t>* replacementNode;
    bool oldIsRed = shanchuRBT->isRed();
    BSTNode<key_t,val_t>* leftSon = shanchu->getLeftChild();
    BSTNode<key_t,val_t>* rightSon = shanchu->getRightChild();
    BSTForwardIterator<key_t,val_t> successor = pos;
    successor.next();
    BSTNode<key_t,val_t>* nextNode = successor.current;
    RBTNode<key_t,val_t>* nextNodeRBT = dynamic_cast<RBTNode<key_t, val_t>* >(nextNode);
    if (shanchu->getLeftChild() == this->sentinel) {
        replacementNode = rightSon;
        transplant(shanchu,rightSon);
    } else if (shanchu->getRightChild() == this->sentinel) {
        replacementNode = leftSon;
        transplant(shanchu,leftSon);
    } else { 
        oldIsRed = nextNodeRBT->isRed();
        replacementNode = nextNode->getRightChild();
        if (nextNode->getParent() == shanchu) {
            replacementNode->setParent(nextNode);
        } else {
            transplant(nextNode,nextNode->getRightChild());
            nextNode->setRightChild(shanchu->getRightChild());
            nextNode->getRightChild()->setParent(nextNode);
        }
        transplant(shanchu,nextNode);
        nextNode->setLeftChild(leftSon);
        leftSon->setParent(nextNode);
        nextNodeRBT->setIsRed(shanchuRBT->isRed());
    }
    this->numItems--;
    delete shanchu;
    if (!oldIsRed) {
        deleteFixup(dynamic_cast<RBTNode<key_t, val_t>* >(replacementNode));
    }
    return successor;
}


template <class key_t, class val_t>   
void RBTMultimap<key_t,val_t>::deleteFixup(RBTNode<key_t, val_t>* replacementNode) {
    RBTNode<key_t,val_t>* root = dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
    while ((replacementNode != root) && (replacementNode->isRed() == false)) {
        RBTNode<key_t,val_t>* parent = replacementNode->getParent();
        if (replacementNode == parent->getLeftChild()) {
            RBTNode<key_t,val_t>* sibling = parent->getRightChild();
            if (sibling->isRed()) {
                sibling->setIsRed(false);
                parent->setIsRed(true);
                rotateLeft(parent);
                sibling = parent->getRightChild();
            }
            if (!sibling->getLeftChild()->isRed() && !sibling->getRightChild()->isRed()) {
                sibling->setIsRed(true);
                replacementNode = parent;
            } else {
                if (!sibling->getRightChild()->isRed()) {
                    sibling->getLeftChild()->setIsRed(false);
                    sibling->setIsRed(true);
                    rotateRight(sibling);
                    sibling = parent->getRightChild();
                }
                sibling->setIsRed(parent->isRed());
                parent->setIsRed(false);
                sibling->getRightChild()->setIsRed(false);
                rotateLeft(parent);
                replacementNode = root;
            }
        } else {
            RBTNode<key_t,val_t>* sibling = parent->getLeftChild();
            if (sibling->isRed()) {
                sibling->setIsRed(false);
                parent->setIsRed(true);
                rotateRight(parent);
                sibling = parent->getLeftChild();
            } if (!sibling->getLeftChild()->isRed() && !sibling->getRightChild()->isRed()) {
                sibling->setIsRed(true);
                replacementNode = parent;
            } else {
                if (!sibling->getLeftChild()->isRed()) {
                    sibling->getRightChild()->setIsRed(false);
                    sibling->setIsRed(true);
                    rotateLeft(sibling);
                    sibling = parent->getLeftChild();
                }
                sibling->setIsRed(parent->isRed());
                parent->setIsRed(false);
                sibling->getLeftChild()->setIsRed(false);
                rotateRight(parent);
                replacementNode = root;
            }
        }
    }
    replacementNode->setIsRed(false);
}





template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::printDOT(std::string filename)
{
   using namespace std;
   ofstream fout(filename.c_str());

   long long counter = 1;
   map<RBTNode<key_t, val_t>*, long long> nodeToCounter;
   nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] = counter;
   counter++;

   fout << "digraph RBTMultimap {" << endl;

   fout << "\t node" << nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] << " [label=\"nil\", style=filled, color=grey, fontcolor=white];" << endl;

   if(this->root != this->sentinel)
   {
      RBTNode<key_t, val_t>* rt = dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
      if(!nodeToCounter[rt])
      {
	 nodeToCounter[rt] = counter;
	 counter++;
      }
      if(!nodeToCounter[rt->getParent()])
      {
	 nodeToCounter[rt->getParent()] = counter;
	 counter++;
      }
      fout << "\t node" << nodeToCounter[rt] << " -> node" << nodeToCounter[rt->getParent()] << " [constraint=false, tailport=n, headport=s";
      if(rt->getParent() == this->sentinel)
      {
	 fout << ", color=grey];" << endl;
      }
      else
      {
	 //The root's parent is something weird!! Make the arrow orange so it sticks out
	 fout << ", color=orange];" << endl;
      }

      map<RBTNode<key_t, val_t>*, bool> printed;
   
      queue<RBTNode<key_t, val_t>* > q;
      q.push(rt);
      while(!q.empty())
      {
	 RBTNode<key_t, val_t>* node = q.front();
	 q.pop();

	 printed[node] = true;
      
	 //Set up node's appearance
	 if(!nodeToCounter[node])
	 {
	    nodeToCounter[node] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " [label=\"k: " << node->getKey() << "\", style=filled, color=";
	 if(node->isRed())
	 {
	    fout << "red";
	 }
	 else
	 {
	    fout << "black, fontcolor=white";
	 }
	 fout << "];" << endl;

	 //Set up child links
	 //First the left node
	 if(!nodeToCounter[node->getLeftChild()])
	 {
	    nodeToCounter[node->getLeftChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getLeftChild()] << " [tailport=sw";    
	 if(node->getLeftChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getLeftChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getLeftChild());
	 }

	 if(node->getLeftChild() != this->sentinel)
	 {
	    if(node->getLeftChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getLeftChild()->getParent()])
	       {
		  nodeToCounter[node->getLeftChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getLeftChild()] << " -> node" << nodeToCounter[node->getLeftChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }

	 //Now the right node
	 if(!nodeToCounter[node->getRightChild()])
	 {
	    nodeToCounter[node->getRightChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getRightChild()] << " [tailport=se";    
	 if(node->getRightChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getRightChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getRightChild());
	 }

	 if(node->getRightChild() != this->sentinel)
	 {
	    if(node->getRightChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getRightChild()->getParent()])
	       {
		  nodeToCounter[node->getRightChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getRightChild()] << " -> node" << nodeToCounter[node->getRightChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }
      }
   }
   fout << "}" << endl;
}

