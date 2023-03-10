//genbst.h
//NAME: ESHAN JOSHI

#ifndef GENBST_H
#define GENBST_H

using namespace std;

// Replace the following existing definition of GenBST with the new class definition
template <class T>
class GenBST {
    public:
        GenBST();
        ~GenBST(); 
        bool insert(T value);
        void printPreOrder() const;
        void printInOrder() const;
        void printPostOrder() const;
        T sum() const;
        int count() const;
        bool contains(T value) const;
        T getPredecessor(T value) const;
        T getSuccessor(T value) const;
        bool remove(T value);
        // int minVal() const;
        // int maxVal() const;

    private:
        struct Node {
            T info;
            Node *left, *right, *parent;
            Node (T v = 0) : info(v), left(0), right(0), parent(0) {}
        };
        Node *root;
        Node* getNodeFor(T value, Node* n) const;
        void clear(Node *n);
        bool insert(T value, Node *n);
        void printPreOrder(Node *n) const;
        void printInOrder(Node *n) const;
        void printPostOrder(Node *n) const;
        T sum(Node *n) const;
        int count(Node *n) const;
        Node* getSuccessorNode(T value) const;
        Node* getPredecessorNode(T value) const;
        
};

#include "genbst.cpp"

#endif

// template <typename T>
// inline GenBST<T>::GenBST()
// {
// }
