//
// Created by kwd on 17/10/2019.
//

#ifndef BST_EX11_NODES_H
#define BST_EX11_NODES_H

using namespace std;
class Node{
private:
    int key;
    float x;
    float y;
    Node* leftChild;
    Node* rightChild;
    Node* parent;
public:
    Node(int cle): key(cle) {
        x,y = 0;
        leftChild = nullptr;
        rightChild = nullptr;
        parent = nullptr;
    }

    Node(Node* node){
        key= node->getKey();
        x = node->getX();
        y = node->getY();
        leftChild = node->getLeftChild();
        rightChild = node->getRightChild();
        parent = node->getParent();
    }

    int getKey() const {
        return key;
    }

    void setKey(int key) {
        Node::key = key;
    }

    float getX() const {
        return x;
    }

    void setX(float x) {
        Node::x = x;
    }

    float getY() const {
        return y;
    }

    void setY(float y) {
        Node::y = y;
    }

    Node *getLeftChild() const {
        return leftChild;
    }

    void setLeftChild(Node *leftChild) {
        Node::leftChild = leftChild;
    }

    Node *getRightChild() const {
        return rightChild;
    }

    void setRightChild(Node *rightChild) {
        Node::rightChild = rightChild;
    }

    Node *getParent() const {
        return parent;
    }

    void setParent(Node *parent) {
        Node::parent = parent;
    }
};


#endif //BST_EX11_NODES_H
