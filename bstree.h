#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    private:
        Node<T> *root;

    public:
        BSTree() : root(nullptr) {};

        bool find(T data) { 
            Node<T>* aux = this->root;
            while(aux != nullptr){
                if(data > aux->data){
                    aux = aux->right;
                }
                if(data < aux->data){
                    aux = aux->left;
                }
                if(data == aux->data){
                    return true;
                }
                }else{
                    return false;
                }
            }
        } 

        bool insert(T data) {
            
            Node<T>* aux = this->root;
            Node<T>* inserted = new Node<T>();
            while(aux->left != nullptr || aux->right != nullptr){
                if(data == aux->data){
                    return false;
                if(data < aux->data){
                    aux = aux->left;
                }
                if(data > aux->data){
                    aux = aux->right;
                }
            }
                if(data < aux->data){
                    inserted = aux->left;
                    inserted->data = data;
                }
                if(data > aux->data){
                    inserted = aux->right;
                    inserted->data = data;
                }

        }

        bool remove(T data) {

        }


        unsigned int size_recursive(Node* node)
            if(this->node == nullptr){
                return 0;
            }else
            return size_recursive(this->node->left) + size_recursive(this->node->right) +1;

        unsigned int size() {
            if (this->root == nullptr){
                return 0;
            }else
            return size_recursive(this->root->left) + size_recursive(this->root->right) + 1;
        }


        void traversePreOrder_recursive(Node* node){
            if (node == nullptr){
                return;
            }
            cout<< node->data<<" ";
            traversePreOrder_recursive(node->left);
            traversePreOrder_recursive(node->right);
        }

        void traverseInOrder_recursive(Node* node){
            if (node == nullptr){
                return;
            }
            traverseInOrder_recursive(node->right);
            cout<< node->data<<" ";
            traverseInOrder_recursive(node->left);
        }

        void traversePostOrder_recursive(Node* node){
            if (node == nullptr){
                return;
            }
            traversePostOrder_recursive(node->right);
            traversePostOrder_recursive(node->left);
            cout<< node->data<<" ";
        }

        void traversePreOrder() {
            if (this->root == nullptr){
                return;
            }
            cout<< this->root->data<<" ";
            traversePreOrder_recursive(this->root->right);
            traversePreOrder_recursive(this->root->left);
        }

        void traverseInOrder() {
            if (this->root == nullptr){
                return;
            }
            traverseInOrder_recursive(this->root->right);
            cout<< this->root->data<<" ";
            traverseInOrder_recursive(this->root->left);
        }

        void traversePostOrder() {
            if (this->root == nullptr){
                return;
            }
            traversePostOrder_recursive(this->root->right);
            traversePostOrder_recursive(this->root->left);
            cout<< this->root->data<<" ";
        }

        Iterator<T> begin() {
            // TODO
        }

        Iterator<T> end() { 
            // TODO
        }

        ~BSTree() {
            // TODO
        }
};

#endif
