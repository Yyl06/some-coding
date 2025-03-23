#include <iostream>

typedef struct Node{
    int data;
    Node* Left;
    Node* Right;

    Node(int data){
        this->data = data;
        this->Left = this->Right = nullptr;
    }
}Nodes;

class BinaryTree{
    private:
        Node *Root;

    public:
        BinaryTree(){
            Root = nullptr;
        }

        Node *Insert(Nodes *Node, int data){
            if(Node == nullptr){
                Node = new Nodes(data);
            }else if(data <= Node->data){
                Node->Left = Insert(Node->Left, data);
            }else{
                Node->Right = Insert(Node->Right, data);
            }
            return Node;
        }
        void Insert(int data){
            Root = Insert(Root, data);
        }

        //Inorder Traversal (Left -> Root -> Right)
        Node *Inorder(Node *Node, int data){
            if(Node == nullptr){
                return nullptr;
            }else{
                Inorder(Node->Left, data);//Left Data
                std::cout << Node->data << " ";//Root
                Inorder(Node->Right, data);//Right Data
            }
            return Node;
        }
        void Inorder(){
            Inorder(Root, 0);
            std::cout << "\n";
        }

        //Preorder Traversal (Root -> Left -> Right)
        Node *Preorder(Node *Node, int data){
            if(Node == nullptr){
                return nullptr;
            }else{
                std::cout << Node->data << " "; //Root
                Preorder(Node->Left, data);//Left Data
                Preorder(Node->Right, data);//Right Data
            }
            return Node;
        }
        void Preorder(){
            Preorder(Root, 0);
            std::cout << "\n";
        }

        //Postorder Traversal (Left -> Right -> Root)
        Node *Postorder(Node *Node, int data){
            if(Node == nullptr){
                return nullptr;
            }else{
                Postorder(Node->Left, data);//Left Data
                Postorder(Node->Right, data);//Right Data
                std::cout << Node->data << " ";//Root
            }
            return Node;
        }
        void Postorder(){
            Postorder(Root, 0);
            std::cout << "\n";
        }
};

int main(){
    BinaryTree *Tree = new BinaryTree();
    Tree->Insert(10);
    Tree->Insert(5);
    Tree->Insert(15);
    Tree->Insert(3);
    Tree->Insert(7);
    Tree->Insert(12);
    Tree->Insert(17);

    //Inorder, Arranges the data in ascending order
    Tree->Inorder();
    //Preorder, Root is printed first, which is the first element, then the elements are assigned from when they are inserted
    Tree->Preorder();
    //Postorder, Arranges the data in descending order
    Tree->Postorder();

    return 0;
}