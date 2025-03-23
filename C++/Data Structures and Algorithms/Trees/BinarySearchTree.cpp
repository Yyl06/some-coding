#include <iostream>

typedef struct BinarySearch{
    int data;
    BinarySearch *Left, *Right;

    BinarySearch(int data) : data(data), Left(nullptr), Right(nullptr) {};
}Binary;

class BinarySearchTree{
    private:
        Binary *Root;

        Binary *Insert(Binary *Node, int data){
            if(!Node){
                return new Binary(data);
            }
            if(data < Node->data){
                Node->Left = Insert(Node->Left, data);
            }else{
                Node->Right = Insert(Node->Right, data);
            }
            return Node;
        }

        Binary *Search(Binary *Node, int data){
            if(!Node || Node->data == data){
                return Node;
            }
            if(data < Node->data){
                return Search(Node->Left, data);
            }
            return Search(Node->Right, data);
        }

        void InOrder(Binary *Node){
            if(!Node) return;
            InOrder(Node->Left);
            std::cout << Node->data << " ";
            InOrder(Node->Right);
        }

    public:
        BinarySearchTree(){
            this->Root = nullptr;
        }

        void Insert(int data){
            Root = Insert(Root, data);
        }

        bool Search(int data){
            return Search(Root, data) != nullptr;
        }

        void InOrder(){
            InOrder(Root);
            std::cout << "\n";
        }
};

int main(){
    BinarySearchTree BST;

    BST.Insert(10);
    BST.Insert(5);
    BST.Insert(15);
    BST.Insert(2);
    BST.Insert(7);
    BST.Insert(12);
    BST.Insert(18);

    std::cout << "BST Inorder Traversal: ";
    BST.InOrder();

    std::cout << "Searching for 7.. " << (BST.Search(7) ? "Found" : "Not Found") << "\n";
    std::cout << "Searching for 20.. " << (BST.Search(20) ? "Found" : "Not Found") << "\n";

    return 0;
}