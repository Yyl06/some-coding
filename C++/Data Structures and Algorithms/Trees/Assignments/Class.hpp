#ifndef ClassBT_hpp
#define ClassBT_hpp

#include <iostream>
#include <queue>
#include <cstdlib>
#include <iomanip>
#include "Node.hpp"

class BinaryTree {
private:
    Node* Root;

    // 🌱 Recursive Random Tree Generation
    Node* generateRandomTree(int depth, int maxDepth) {
        if (depth > maxDepth || rand() % 3 == 0) return nullptr;
        Node* node = new Node(rand() % 100);
        node->Left = generateRandomTree(depth + 1, maxDepth);
        node->Right = generateRandomTree(depth + 1, maxDepth);
        return node;
    }

    //Inorder (Left -> Root -> Right)
    void Inorder(Node* node) {
        if (!node) return;
        Inorder(node->Left);
        std::cout << node->data << " ";
        Inorder(node->Right);
    }

    //Preorder (Root -> Left -> Right)
    void Preorder(Node* node) {
        if (!node) return;
        std::cout << node->data << " ";
        Preorder(node->Left);
        Preorder(node->Right);
    }

    //Postorder (Left -> Right ->)
    void Postorder(Node* node) {
        if (!node) return;
        Postorder(node->Left);
        Postorder(node->Right);
        std::cout << node->data << " ";
    }

public:
    // 🌲 Constructor (Generates Random Tree)
    BinaryTree(int MaxDepth = 4) {
        srand(time(0));
        Root = generateRandomTree(1, MaxDepth);
    }

    // 🔗 Insert into BST
    Node* Insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data <= node->data) {
            node->Left = Insert(node->Left, data);
        } else {
            node->Right = Insert(node->Right, data);
        }
        return node;
    }
    
    void Insert(int data) {
        Root = Insert(Root, data);
    }

    // 🔍 Inorder Traversal
    void Inorder() {
        std::cout << "📜 Inorder: ";
        Inorder(Root);
        std::cout << "\n";
    }

    // 🚀 Preorder Traversal
    void Preorder() {
        std::cout << "📜 Preorder: ";
        Preorder(Root);
        std::cout << "\n";
    }

    // 🔚 Postorder Traversal
    void Postorder() {
        std::cout << "📜 Postorder: ";
        Postorder(Root);
        std::cout << "\n";
    }

    // 🌳 Level Order Traversal (BFS)
    void LevelOrder() {
        if (!Root) {
            std::cout << "📢 [Empty Tree]\n";
            return;
        }
        std::cout << "📢 Level Order: ";

        std::queue<Node*> q;
        q.push(Root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            std::cout << curr->data << " ";
            if (curr->Left) q.push(curr->Left);
            if (curr->Right) q.push(curr->Right);
        }
        std::cout << "\n";
    }

    //Vector is easier..
    void displayTree() {
        if (!Root) {
            std::cout << "🌲 [Empty Tree] 🌲\n";
            return;
        }
    
        std::queue<Node*> q;
        q.push(Root);
        
        int depth = 0;
        int maxWidth = 64; // Adjust this for better spacing
    
        while (!q.empty()) {
            int size = q.size();
            int spaces = maxWidth / (size + 1);
            std::cout << "\n";
    
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
    
                if (node) {
                    std::cout << std::setw(spaces) << node->data;
                    q.push(node->Left);
                    q.push(node->Right);
                } else {
                    std::cout << std::setw(spaces) << " ";
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }
    
            std::cout << "\n";
            depth++;
    
            // Stop printing if the entire next level is empty
            bool allNull = true;
            std::queue<Node*> tempQueue = q;
            while (!tempQueue.empty()) {
                if (tempQueue.front() != nullptr) {
                    allNull = false;
                    break;
                }
                tempQueue.pop();
            }
            if (allNull) break;
        }
    }

};

#endif