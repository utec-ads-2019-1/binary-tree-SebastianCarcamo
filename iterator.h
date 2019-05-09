#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>
template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        std::stack<Node<T>*> myStack;

    public:
        Iterator() {
            current = nullptr;
        }

        Iterator(Node<T> *node, bool SoE) {
            current = node;
            if(SoE){
                while(current->left){
                    current.push(this->myStack);
                    current = current->left;
                }
            }
            else{
                while(current->right){
                    current.push(this->myStack);
                    current = current->right;
                }
            }
        };

        Iterator<T> operator=(Iterator<T> other) {          
            current = other.current;
            myStack = other.myStack;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            return this->current!=other->current;
        }

        Iterator<T> operator++() {
            // TODO
        }

        Iterator<T> operator--() {
            // TODO
        }

        T operator*() {
            // TODO
        }
};

#endif
