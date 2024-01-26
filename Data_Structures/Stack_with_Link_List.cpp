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
void push(Node** head,int newValue){
	Node *newNode=new Node();
	newNode->Value=newValue;
	newNode->Next=*head;
	*head =newNode;
}
void pop(Node** head){
	Node *newNode=*head;
	*head=(*head)->Next;
	delete newNode;
}
int main(){
	Node* head=new Node();
	Node* second=new Node();
	Node* third=new Node();
	
	head->Value=1;
	head->Next=NULL;
	push(&head,0);
	push(&head,2);
	pop(&head);
	printList(head);
	
	return 0;
}
