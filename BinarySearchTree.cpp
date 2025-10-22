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

    // 1. In-order traversal (LDR)
    void inOrderTraversal(Node* node){

        if (node != nullptr) {
            // keeps going to the left until theres no more 'left' nodes on the left
            inOrderTraversal(node -> left);
            cout << node -> data << "" ;
            inOrderTraversal(node -> right);
        }
    }

    // 2. Preorder travseral (DLR)
    void preOrderTraversal(Node* node){

        if (node!=nullptr) {
            cout << node->data << "" ;
            preOrderTraversal(node -> left);
            preOrderTraversal(node -> right);
        }
    }

    // 3. Postorder traversal (LRD)
    void postOrderTraversal(Node* node){

        if(node!=nullptr){
            postOrderTraversal(node -> left);
            postOrderTraversal(node -> right);
            cout << node->data << "" ;

        }
    }

    // 4. Search for a node:
    bool search (Node* node, int value) {
        
        if (node ==nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        }

        else if (value < node->data) {
            return search(node->left, value);
        }
        
        else {
            return search(node->right, value);
        }
    }

    // 5. Find minimum value node:
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // 6. Find maximum value node:
    Node* findMax(Node* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // 7. Delete a node:
    Node* deleteNode(Node* root, int value) {
    if (root == nullptr)
        return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } 
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } 
    else { 
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } 
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } 
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
};
};


// Driver code
int main() {
    Tree tree;

// 1. Insert nodes
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "In-order traversal: ";
    tree.inOrderTraversal(tree.root);
    cout << endl;

    cout << "Pre-order traversal: ";
    tree.preOrderTraversal(tree.root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrderTraversal(tree.root);
    cout << endl;

// 2. Search for a node
    int searchValue = 40;
    cout << "Searching for " << searchValue << ": ";
    if (tree.search(tree.root, searchValue)) {
        cout << "Found!" << endl;
    } else {
        cout << "Not found!" << endl;
    }

// 3. Find minimum and maximum node
    Node* minNode = tree.findMin(tree.root);
    Node* maxNode = tree.findMax(tree.root);
    cout << "Minimum value in the tree: " << minNode->data << endl;
    cout << "Maximum value in the tree: " << maxNode->data << endl;

// 4. Delete a node
    tree.root = tree.deleteNode(tree.root, 40);
    cout << "After deleting 40, In-order traversal: ";
    tree.inOrderTraversal(tree.root);
    cout << endl;

    return 0;
}