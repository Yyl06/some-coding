#include <iostream>
#include <new>

typedef struct Library{
    int data;
    Library *Next;

    Library(int data){
        this->data = data;
        this->Next = nullptr;
    }
}Librarys;

class LinkedList{
    int size;
    Librarys *Head;

    public:
    LinkedList(){
        this->Head = nullptr;
        this->size = 0;
    }

    bool Add(int data){
        Librarys *NewLibrary = new Library(data);
        try{
            if(this->Head == nullptr){
                this->Head = NewLibrary;
            }else{
                NewLibrary->Next = this->Head;
                this->Head = NewLibrary;
            }this->size++;
            return true;
        }catch(std::bad_alloc &){
            return false;
        }
        return false;
    }

    bool Remove(int data){
        if(this->Head == nullptr){
            return false;
        }else{
            Librarys *Current = this->Head;
            this->Head = this->Head->Next;
            delete Current;
            this->size--;
            return true;
        }
    }

    bool Search(int data){
        Librarys *temp = this->Head;;
        while(temp != nullptr && temp->data != data){
                return temp = temp->Next;
            }
        return temp != nullptr;
    }

    void Display(){
        Librarys *temp = this->Head;
        while(temp != nullptr){
            std::cout << temp->data << " ";
            temp = temp->Next;
        }
        std::cout << "No Data Found" << std::endl;
    }

    void ReverseDisplay(){
        //Previous, Next must be Empty, Current is Head because we start from the Head
        Librarys *Previous = nullptr;
        Librarys *Current = this->Head;
        Librarys *Next = nullptr;

        //While Current is not Empty, Points Next to Next, Current to Previous, Previous to Current, Current to Next
        while(Current != nullptr){
            Next = Next->Next;
            Current->Next = Previous;
            Previous = Current;
            Current = Next;
        }
        //Head to be initialized to Previous
        Head = Previous;

        //While Current is not Empty, Print Head to Data, then Move Head to Next
        while(Head != nullptr){
            std::cout << Head->data << " ";
            Head = Head->Next;
        }
        std::cout << "\n";
    }
};

int main(){
    LinkedList List;
    int data;
    int choice;
    std::string exit;
    std::cout << "1. Add Data" << std::endl;
    std::cout << "2. Remove Data" << std::endl;
    std::cout << "3. Search Data" << std::endl;
    std::cout << "4. Display Data" << std::endl;
    std::cout << "5. Reverse Display Data" << std::endl;
    do{
        std::cout << "Enter Your Choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter the number you want to add: ";
                std::cin >> data;
                if (List.Add(data)){
                    std::cout << "Data Added Successfully" << std::endl;
                }else{
                    std::cout << "Failed to add data" << std::endl;
                }
                break;

            case 2:
                if (List.Remove(data)){
                    std::cout << "Data Removed Successfully" << std::endl;
                }else{
                    std::cout << "Failed to remove data" << std::endl;
                }
                break;

            case 3:
                std::cout << "Enter the number you want to search: ";
                std::cin >> data;
                if (List.Search(data)){
                    std::cout << "Data Found" << std::endl;
                }else{
                    std::cout << "Data Not Found" << std::endl;
                }
                break;

            case 4:
                List.Display();
                break;

            case 5:
                List.ReverseDisplay();
                break;

            default:
                std::cout << "Invalid Choice" << std::endl;
                break;
        }
    }while(exit != "exit");
    return 0;
}