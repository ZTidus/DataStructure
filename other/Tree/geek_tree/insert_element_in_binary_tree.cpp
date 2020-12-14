#include <iostream>
#include <queue>
using namespace std;

/* A binary tree node has key, pointer to left child and a pointer to right
 * child */
struct Node {
    int key;
    struct Node* left, *right;
};

/* Function to create a new node of tree and return pointer. */
struct Node* newNode(int key) {
    struct Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

/* Inorder traversal of a binary tree. */
void inorder(struct Node* temp) {
    if(!temp)
        return;
    inorder(temp->left);
    cout << temp->key << " ";
    inorder(temp->right);
}

/* Function to insert element in binary tree. */
void insert(struct Node* temp, int key) {
    queue<struct Node*> q;
    q.push(temp);
    // Do level order traversal until we find.
    while(!q.empty()) {
        struct Node* temp = q.front();
        q.pop();

        if(!temp->left) {
            temp->left = newNode(key);
            break;
        } else 
            q.push(temp->left);
        
        if(!temp->right) {
            temp->right = newNode(key);
            break;
        } else 
            q.push(temp->right);
    }
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(1);
    root->left->left = newNode(11);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
    /*
     *         10
     *        /  \
     *      1     9
     *     /     / \
     *   11    15   8
     */
    cout << "Inorder traversal before insertion:";
    inorder(root);

    int key = 12;
    insert(root, key);

    cout << endl;
    cout << "Inorder traversal after insertion:";
    inorder(root);

    return 0;
}
