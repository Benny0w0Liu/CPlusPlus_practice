#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int Data){
	Node* newNode = new Node();
	newNode->data = Data;
	newNode->left = newNode->right = nullptr;
	return newNode;
}

//preorder: data->left->right
void printTree_preorder(Node* root,int n){
	if(root == nullptr){
		return;
	}
	for(int i=0;i<n;i++){
		cout<<" ";
	}
	cout<<root->data<<endl;
	printTree_preorder(root->left,n+1);
	printTree_preorder(root->right,n+1);
}
//inorder: left->data->right
 void printTree_inorder(Node* root,int n){
	if(root == nullptr){
		return;
	}
	printTree_inorder(root->left,n+1);
	for(int i=0;i<n;i++){
		cout<<"  ";
	}
	cout<<root->data<<endl;
	printTree_inorder(root->right,n+1);
}
//posorder: left->right->data
 void printTree_posorder(Node* root,int n){
	if(root == nullptr){
		return;
	}
	printTree_posorder(root->left,n+1);
	printTree_posorder(root->right,n+1);
	for(int i=0;i<n;i++){
		cout<<"  ";
	}
	cout<<root->data<<endl;
	
}
int main(){
	Node* root = createNode(1);
	
	root->left = createNode(2);
	root->right = createNode(3);
	
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	
	root->left->left->left = createNode(9);
	root->right->right->left = createNode(15);
	printTree_posorder(root,0);
	return 0;
} 
