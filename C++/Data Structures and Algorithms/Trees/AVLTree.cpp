#include <iostream>
using std::cout, std::max;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

// Get height of a node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Get balance factor
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Right rotate (LL case)
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // New root
}

// Left rotate (RR case)
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // New root
}

// Insert function
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // No duplicates

    // Update height
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Get balance factor
    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    // RR Case
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    // LR Case
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RL Case
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root; // Unchanged
}

// Inorder traversal (sorted output)
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal of AVL tree: ";
    inorder(root);
    cout << "\n";

    return 0;
}
