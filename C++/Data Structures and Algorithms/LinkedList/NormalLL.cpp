#ifndef LL_H
#define LL_H
#include <iostream>
using namespace std;

typedef char DATA;

typedef struct NODE{
	DATA data;
	NODE* link;
}node;


class List{
	private:
		NODE *pHead;
		int count;
		NODE *pPre;
		NODE *pLoc;
		
	public:
		bool add(DATA dataIn);
		bool remove(DATA dataOut);
		bool search(DATA target);
		bool isEmpty();
		void display();
		List();
		
};

List::List(){
	pHead = NULL;
	count = 0;
}

bool List::add(DATA dataIn){
	NODE *pNew;
	try {
		pNew = new NODE();
		pNew ->data = dataIn;
		if(search(dataIn)){
			return false;
		}else{
			if(pPre == NULL){
				pNew->link = pHead;
				pHead = pNew;
			}else{
				pNew->link = pPre->link;
				pPre->link = pNew;
			}
			count++;
			return true;
		}
	}catch(bad_alloc &){
		return false;
	}
	return false;
	}
	
bool List::remove(DATA dataOut){
	if(!isEmpty()){
		if(search(dataOut)){
			if(pPre == NULL){
				pHead = pLoc->link;
			}else{
				pPre->link = pLoc->link;
			}
			count--;
			delete(pLoc);
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
	return false;
}
bool List::search(DATA target){
	bool found = false;
	pPre = NULL;
	pLoc = pHead;
	while((pLoc != NULL) && (target > pLoc->data)){
		pPre = pLoc;
		pLoc = pLoc->link;
	}
	
	if(pLoc == NULL){
		found = false;
	}else{
		found = (target == pLoc->data);
	}
	return found;
}
bool List::isEmpty(){
	return count == 0;
}

void List::display(){
	NODE *pWalk;
	if(isEmpty()){
		cout << "List is empty.";
	}else{
		pWalk = pHead;
		cout << "List content: ";
		while(pWalk !=NULL){
			cout << pWalk->data << " ";
			pWalk = pWalk->link;
		}
	}
}

#endif


int main(){
    List list;
    list.add('A');
    list.add('B');
    list.add('C');
    list.add('D');
    list.add('E');
    list.display();
    list.remove('C');
    list.display();
    return 0;
}