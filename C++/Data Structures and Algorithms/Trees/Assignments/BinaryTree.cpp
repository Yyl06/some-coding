#include <iostream>
#include <ctime>
#include "Class.hpp"

int main(){
    srand(time(0)); // Seed RNG
    BinaryTree Root(4);

    std::cout << "\n🎲 Generated Binary Tree:\n";
    Root.displayTree();

    std::cout << "\n📜 Inorder Traversal: ";
    Root.Inorder();
    
    std::cout << "\n🚀 Preorder Traversal: ";
    Root.Preorder();
    
    std::cout << "\n🎯 Postorder Traversal: ";
    Root.Postorder();
    
    std::cout << "\n🏗️ Level Order Traversal: \n";
    Root.LevelOrder();
    
    std::cout << "\n";
    return 0;
}