#include<iostream>
using namespace std;
class Node{
	public:
		int value;
		Node* next;
};

void push(Node** head, int newValue){
	Node* newNode = new Node();
	newNode->value=newValue;
	newNode->next=NULL;
	 
	if(*head == NULL){
	 	*head =newNode;
	 	return;
	}
	  
	Node *last=*head;
	while(last->next!=NULL){
		last = last->next;
	}
	last->next=newNode;
}
void pop(Node** head){
	if(*head==NULL){
		cout<<"Queue is empty"<<endl;
		return;
	}
	Node *newNode=*head;
	*head=(*head)->next;
	delete newNode;
}
void printQueue(Node* head){
	Node* current=head;
	while(current!=NULL){
		cout<<current->value<<endl;
		current=current->next;
	}
}
int main(){
	Node* head=new Node();
	head->value=0;
	head->next=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	pop(&head);
	pop(&head);
	pop(&head);
	pop(&head);
	
	printQueue(head);
	return 0;
}
