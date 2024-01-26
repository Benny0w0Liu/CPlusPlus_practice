#include<iostream>
using namespace std;

class Node{
public:
	int Value;
	Node* Next;
};

void printList(Node* n){
	while(n!=NULL){
		cout<<n->Value<<endl;
		n=n->Next;
	}
}
void insertAtTheFront(Node** head,int newValue){
	Node *newNode=new Node();
	newNode->Value=newValue;
	newNode->Next=*head;
	*head =newNode;
}
void insertAtTheEnd(Node** head,int newValue){
	Node* newNode = new Node();
	newNode->Value=newValue;
	newNode->Next=NULL;
	 
	if(*head == NULL){
	 	*head =newNode;
	 	return;
	}
	  
	Node *last=*head;
	while(last->Next!=NULL){
		last = last->Next;
	}
	last->Next=newNode;
}
void insertAfter(Node* previous, int newValue){
	if(previous==NULL){
		cout<<"Previous can not be NULL!"<<endl;
		return;
	}
	
	Node* newNode= new Node();
	newNode->Value=newValue;
	
	newNode->Next=previous->Next;
	previous->Next=newNode;
}

int main(){
	Node* head=new Node();
	Node* second=new Node();
	Node* third=new Node();
	
	head->Value=1;
	head->Next=second;
	
	second->Value=2;
	second->Next=third;
	
	third->Value=3;
	third->Next=NULL;
	insertAtTheFront(&head,0);
	insertAtTheEnd(&head,4);
	insertAtTheEnd(&head,5);
	insertAfter(second,-1);
	printList(head);
	
	delete head;
	head=NULL;
	delete second;
	second=NULL;
	delete third;
	third=NULL;
	return 0;
}
