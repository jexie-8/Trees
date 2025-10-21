#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node (int value) {
        data = value;
        left = right = nullptr;
    }
};


class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }


    // Function to insert a node
    Node* insert(Node* node, int value) {

        if (node ==nullptr) {
            return new Node(value);
        }

        if (value < node -> data ) {
            node->left = insert ( node -> left,value );
        }

        else {
            node->right = insert ( node -> right,value );
        }

        return node;
    }

    // 1. In order traversal
    void inOrderTraversal(Node* node){

        if (node != nullptr) {
            // keeps going to the left until theres no more nodes on the left
            inOrderTraversal(node -> left);
            cout << node -> data << "" ;
            inOrderTraversal(node -> right);
        }
    }


    // 2. Preorder travseral
    void preOrderTraversal(Node* node){

        if (node!=nullptr) {
            cout << node->data << "" ;
            preOrderTraversal(node -> left);
            preOrderTraversal(node -> right);
        }
    }


    // 3. Postorder traversal
    void postOrderTraversal(Node* node){

        if(node!=nullptr){
            postOrderTraversal(node -> left);
            postOrderTraversal(node -> right);
            cout << node->data << "" ;

        }
    }

};