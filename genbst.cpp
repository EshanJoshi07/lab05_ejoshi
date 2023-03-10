// genbst.cpp
// NAME: ESHAN JOSHI


#include <iostream>
#include <fstream>
#include <string>
#include "genbst.h"


using namespace std;

//template <class T>;

//constructor --> set the root as null
template <class T> 
GenBST<T>::GenBST() {
    root = nullptr;
}

// // // destructor deletes all nodes
template <class T> 
GenBST<T>::~GenBST() {
    clear(root);
}

// //destructor helper --> recrusive 
template <class T>
void GenBST<T>::clear(Node *n) {
    if (n) {
	    clear(n->left);
	    clear(n->right);
	    delete n;
    }
}

// //insert value in tree; return false if duplicate
template <class T>
bool GenBST<T>::insert(T value) {

    //check if tree is empty
    if (!root) {
	    root = new Node(value);
	    return true;
    }

    return insert(value, root);
}

// // //insert helper (assumes n is never 0) --> recrusive 
template <class T>
bool GenBST<T>::insert(T value, Node *n) {
    //check if value = n->info
    if (value == n->info)
	    return false;

    //check if value <n->info --> if value is less also check the left node
    if (value < n->info) {
	    if (n->left) {
	        return insert(value, n->left);
        }
	    else {
	        n->left = new Node(value);
	        n->left->parent = n;
	        return true;
	    }
    }

    //check if value>n->info --> if value is greater also check the left node
    else {
	    if (n->right) {
	        return insert(value, n->right);
        }
	    else {
	        n->right = new Node(value);
	        n->right->parent = n;
	        return true;
	    }
    }
}

// //printPreOrder
template <class T>
void GenBST<T>::printPreOrder() const {
    Node *n = root;
    printPreOrder(n);
}

// //printPreOrder helper --> recursive
template <class T> 
void GenBST<T>::printPreOrder(Node *n) const {
    if (n) {
	    cout << n->info << " ";
	    printPreOrder(n->left);
	    printPreOrder(n->right);
    }
}

// //printInOrder
template <class T>
void GenBST<T>::printInOrder() const {
    Node *n = root;
    printInOrder(n);
}

// //printInOrder helper --> recursive
template <class T>
void GenBST<T>::printInOrder(Node *n) const {
    if (n == NULL){
        return;
    }
    printInOrder(n->left);
    cout << n->info << " ";
    printInOrder(n->right);
}

//printPostOrder
template <class T>
void GenBST<T>::printPostOrder() const {
    Node *n = root;
    printPostOrder(n);
}

//printPostOrder helper --> recursive
template <class T>
void GenBST<T>::printPostOrder(Node *n) const {
    if (n == NULL){
        return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << " ";
}

template <class T>
T GenBST<T>::sum() const {
    Node *n = root;
    return sum(n);
}

// //sum helper --> recursive
template <class T>
T GenBST<T>::sum(Node *n) const {
    if (n == NULL){
        return 0;
    }
    return (n->info + sum(n->left) + sum(n->right));
}

// //counter
template <class T>
int GenBST<T>::count() const {
    Node *n = root;
    return count(n);
}

//counter hlper --> recurvsive
template <class T>
T GenBST<T>::count(Node *n) const {
    if (n == NULL){
        return 0;
    }
    return (1 + count(n->left) + count(n->right));
}

template <class T>
GenBST<T>::Node* GenBST<T>::getNodeFor(T value, Node* n) const{
    if(n==NULL){
        return NULL;
    }
    else if(n->info==value){
        return n;
    }
    else if(n->left==NULL && n->right==NULL){
        return NULL;
    }
    else{
        if(n->info>value){
            return getNodeFor(value,n->left);
        }
        else{
            return getNodeFor(value,n->right);
        }
    }
}

// // returns true if value is in the tree; false if not
template <class T>
bool GenBST<T>::contains(T value) const {   
    return getNodeFor(value,root)!= NULL;
}

// // returns the Node containing the predecessor of the given value
template <class T> 
typename GenBST<T>::Node* GenBST<T>::getPredecessorNode(T value) const{
    Node* temp = getNodeFor(value,root);
    Node* min = root;
    while (min->left){
        min = min->left;
    }
    if (temp == min){
        return 0;
    }
    else {
        if (temp->left){
            temp = temp->left;
            while (temp->right) {
                temp = temp->right;
            }
        }
        else {
            while (temp->parent) {
                if (temp->parent->right == temp){
                    return temp->parent;
                }
                temp = temp->parent;
            }
        }
        return temp;
    }
    
}

// // returns the predecessor value of the given value or 0 if there is none
template <class T> 
T GenBST<T>::getPredecessor(T value) const{
    if (getPredecessorNode(value) == NULL) {
        return 0;
    }
    else {
        return (getPredecessorNode(value))->info;
    }
}

// // returns the Node containing the successor of the given value
template <class T> 
typename GenBST<T>::Node* GenBST<T>::getSuccessorNode(T value) const{
    
    Node* temp = getNodeFor(value,root);
    Node* max = root;
    while (max->right) {
        max = max->right;
    }
    if (temp == max) {
        return 0;
    }
    else {
        if (temp->right) {
            temp = temp->right;
            while (temp->left) {
                temp = temp->left;
            }
        }
        else {
            while (temp->parent) {
                if (temp->parent->left == temp) {
                    return temp->parent;
                }
                temp = temp->parent;
            }
            
        }
        return temp;
    }
}

// returns the successor value of the given value or 0 if there is none
template <class T> 
T GenBST<T>::getSuccessor(T value) const{
    if (getSuccessorNode(value) == NULL) {
        return 0;
    }
    else {
        return (getSuccessorNode(value))->info;
    }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
template <class T> 
bool GenBST<T>::remove(T value){
    Node* temp = getNodeFor(value,root);
    if (temp == NULL) {
        return false;
    }
    if ((temp->left == NULL) && (temp->right == NULL)) {
        if (temp == root) {
            root = NULL;
        }
        else if (temp->parent->left == temp) {
            temp->parent->left = NULL;
        }
        else {
            temp->parent->right = NULL;
        }
        delete temp;
        return true;
    }
    else if (temp->left && temp->right) {
        int num = getPredecessor(temp->info);
        remove(getPredecessor(temp->info));
        temp->info = num;

        return true;
    }
    else{
        Node* c;
        if (temp->left) {
            c = temp->left;
        }
        else {
            c = temp->right;
        }
        if (temp != root) {
            if (temp->parent->left == temp) {
                temp->parent->left = c;
            }
            else {
                temp->parent->right = c;
            }
            c->parent = temp->parent;
        }
        else {
            root = c;
        }
        delete temp;
        return true;
    }
}

//left side has larger values
template <class T> 
T GenBST<T>::minVal() const{
    Node *min = root;
    while (min->left) {
        min = min->left;
    }
    return (min->info);
}

// //right side has larger values
template <class T> 
T GenBST<T>::maxVal() const {
    Node *max = root;
    while (max->right) {
        max = max->right;
    }
    return (max->info);
}