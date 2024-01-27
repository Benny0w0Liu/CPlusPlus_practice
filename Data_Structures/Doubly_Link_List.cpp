#include<iostream>
using namespace std;

class Node{
	public:
		int value;
		Node* next;
		Node* previous;
};
int sizeOfLink(Node* head){
	int n=0;
	Node* traverser = head;
	while(traverser != nullptr){
		traverser= traverser->next;
		n++;
	}
	return n;
}
void insertAfterElement(Node** head,Node** tail, int index ,int Value){	
	if(index==-1){
		Node* node = new Node();
		node->value=Value;
		node->next=*head;
		node->previous=nullptr;
		if(sizeOfLink(*head)==1){
			*tail=*head;
		}
		(*tail)->previous=node;
		*head=node;
		return;
	}
	if(index>=sizeOfLink(*head) || index<0){
		return;
	}
	Node* traverser = *head;
	for(int i=0;i<index;i++){
		traverser= traverser->next;
	}
	Node* nex=traverser->next;
	Node* node = new Node();
	if(index==sizeOfLink(*head)-1){
		node->next=nullptr;
		node->previous=*tail;
		(*tail)->next=node;
		(*tail)=node;
		return;
	}
	node->value=Value;
	node->previous=traverser;
	node->next=nex;
	traverser->next=node;
}
void deleteElement(Node** head,Node** tail, int index){
	if(sizeOfLink(*head)==0 || index>=sizeOfLink(*head) || index<0){
		return;
	}
	if(index==0){
		*head=(*head)->next;
		(*head)->previous=nullptr;
		return;
	}if(index==sizeOfLink(*head)-1){
		*tail=(*tail)->previous;
		(*tail)->next=nullptr;
		return;
	}
	Node* traverser = *head;
	for(int i=0;i<index;i++){
		traverser= traverser->next;
	}
	Node* nex=traverser->next;
	Node* pre=traverser->previous;
	pre->next=nex;
	nex->previous=pre;
	delete traverser;
}
void printFoward(Node* head){
	Node* traverser = head;
	while(traverser != nullptr){
		cout<<traverser->value<<endl;
		traverser= traverser->next;
	}
}
void printBackward(Node* tail){
	Node* traverser = tail;
	while(traverser != nullptr){
		cout<<traverser->value<<endl;
		traverser= traverser->previous;
	}
}
int main(){
	Node* head;
	Node* tail;
	//add 1st node
	Node* node = new Node();
	node->value=4;
	node->next=nullptr;
	node->previous=nullptr;
	
	head=node;
	tail=node;
	//add 2nd node
	node=new Node();
	node->value=5;
	node->next=nullptr;
	node->previous=tail;
	tail->next=node;
	tail=node;
	//add 3rd node
	node=new Node();
	node->value=6;
	node->next=nullptr;
	node->previous=tail;
	tail->next=node;
	tail=node;
	//add 4rd node
	node=new Node();
	node->value=7;
	node->next=nullptr;
	node->previous=tail;
	tail->next=node;
	tail=node;
	deleteElement(&head,&tail,0);
	printFoward(head);
	
	return 0;
} 
