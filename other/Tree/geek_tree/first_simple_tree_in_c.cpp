#include <cstdio>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* newNode(int data) {
    // Accocate memory for new node
    struct node* node = (struct node*)malloc(sizeof(struct node));
    // Assing data to this node
    node->data = data;
    // Initialize left and right children as NULL
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int main() {
    // create root
    struct node *root = newNode(1);
    /*
     *   1
     *  / \
     *NULL NULL
     */
    root->left = newNode(2);
    root->right = newNode(3);
    /*
     *     1
     *    / \
     *   2   3
     * /  \  / \
     *NULL N N  N
     */
    root->left->left = newNode(4);
    getchar();
    return 0;
}
