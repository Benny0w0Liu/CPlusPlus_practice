#include<iostream>
#include<queue>
using namespace std;

void printQueue(queue<string> Q){
	int count=1;
	while(!Q.empty()){
		cout<<count<<". "<<Q.front()<<endl;
		count++;
		Q.pop();
	}
}

int main(){
	queue<string> task;
	string temp;
	cout<<"Input your first task: "<<endl;
	cin>>temp;
	task.push(temp);
	while(!task.empty()){
		cout<<"Input your choice:"<<endl;
		cout<<"1. check the tasks"<<endl;
		cout<<"2. add the task"<<endl;
		cout<<"3. finished the task"<<endl;
		cout<<"0. end the app"<<endl;
		int n;
		cin>>n;
		if(n==0){
			break;
		}else if(n==1){
			printQueue(task);
		}else if(n==2){
			cout<<"Input your new task :"<<endl;
			cin>>temp;
			task.push(temp);
		}else if(n==3){
			task.pop();
		}
	}
	
	
	/*queue<int> myQueue;
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);
	cout<<"Size is "<<myQueue.size()<<endl;
	cout<<"First element is "<<myQueue.front()<<endl;
	cout<<"Last element is "<<myQueue.back()<<endl;
	cout<<"MyQueue:"<<endl;
	printQueue(myQueue);
	*/
	return 0;
}
