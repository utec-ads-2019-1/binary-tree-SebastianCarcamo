#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"
#include <stack>

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
                else{return false;}
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
    }


        Node<T>* get_min(Node<T>* node){
            while(node->left != nullptr){
                node = node->left;
            }
            return node;
        }

        Node<T>* remove_get_node(Node<T>* node, T data){
            if(node == nullptr){
                return node;
            }

            if(data>node->data){
                node->left = remove_get_node(node->left,data);
            }
            else if(data<node->data){
                node->right = remove_get_node(node->right,data);
            }
            else{
                if(root->left == nullptr){
                    Node<T>* temp = node->right;
                    delete node;
                    return temp;
                }
                else if(root->right == nullptr){
                    Node<T>* temp = node->left;
                    delete node;
                }

                Node<T>* temp = get_min(node);
                node->data = temp->data;
                node->right = remove_get_node(node->right,temp->data);
            }
                return node;
        }

        bool remove_recursive(Node<T>* node, T data){
            if(data < node->data){
                node->left = remove_get_node(node->left,data);
                return true;
            }
            else if(data > node->data){
                node->right = remove_get_node(node->right,data);
                return true;
            }
            node = remove_get_node(node,data);
        }

        bool remove(T data) {
            if(this->root == nullptr){
                return false;
            }
            return remove_recursive(this->root,data);
        }


        unsigned int size_recursive(Node<T>* node){
            if(this->node == nullptr){
                return 0;
            }else
            return size_recursive(this->node->left) + size_recursive(this->node->right) +1;
        }
        unsigned int size() {
            if (this->root == nullptr){
                return 0;
            }else
            return size_recursive(this->root->left) + size_recursive(this->root->right) + 1;
        }


        void traversePreOrder_recursive(Node<T>* node){
            if (node == nullptr){
                return;
            }
            std::cout<< node->data<<" ";
            traversePreOrder_recursive(node->left);
            traversePreOrder_recursive(node->right);
        }

        void traverseInOrder_recursive(Node<T>* node){
            if (node == nullptr){
                return;
            }
            traverseInOrder_recursive(node->right);
            std::cout<< node->data<<" ";
            traverseInOrder_recursive(node->left);
        }

        void traversePostOrder_recursive(Node<T>* node){
            if (node == nullptr){
                return;
            }
            traversePostOrder_recursive(node->right);
            traversePostOrder_recursive(node->left);
            std::cout<< node->data<<" ";
        }

        void traversePreOrder() {
            if (this->root == nullptr){
                return;
            }
            std::cout<< this->root->data<<" ";
            traversePreOrder_recursive(this->root->right);
            traversePreOrder_recursive(this->root->left);
        }

        void traverseInOrder() {
            if (this->root == nullptr){
                return;
            }
            traverseInOrder_recursive(this->root->right);
            std::cout<< this->root->data<<" ";
            traverseInOrder_recursive(this->root->left);
        }

        void traversePostOrder() {
            if (this->root == nullptr){
                return;
            }
            traversePostOrder_recursive(this->root->right);
            traversePostOrder_recursive(this->root->left);
            std::cout<< this->root->data<<" ";
        }

        Iterator<T> begin() {
            return Iterator(this->root,true);;
        }

        Iterator<T> end() { 
            return Iterator(this->root,false);
        }

        ~BSTree() {
            // TODO
        }
};

#endif
