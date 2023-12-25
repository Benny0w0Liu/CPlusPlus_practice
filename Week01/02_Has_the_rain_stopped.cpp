#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n<=4){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<"*";
			}
			cout<<"\n";
		}
	}else if(n<=7){
		for(int i=0;i<n;i++){
			for(int j=0;j<i+1;j++){
				cout<<"*";
			}
			cout<<"\n";
		}
	}else{
		bool flag=0;
		int count=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j-count==0){
					cout<<"*";
				}else if(j+count==n-1){
					cout<<"*";
				}else{
					cout<<" ";
				}
			}
			count++;
			cout<<"\n";
		}
	}
}
