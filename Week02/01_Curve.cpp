#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n,direction=0,x=-1,y=0,count=0;
	cin>>n;
	int user[n*n];
	for(int i=0;i<n*n;i++){
		cin>>user[i];
	}
	int arr[n][n];
	int i=0, j=0, di=0, dj=1;
    for (int x=0; x<n*n; x++) {
        arr[i][j] = user[x];
        if(i==j+1 && j<n/2){
        	di=0;
			dj=1;
		}
		if(i+j==n-1 && j>=n/2){
			di=1;
			dj=0;
		}
		if(i==j && j>=n/2){
			di=0;
			dj=-1;
		}
		if(i+j==n-1 && j<n/2){
			di=-1;
			dj=0;
		}
        i+=di; j+=dj;
    }
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<setw(3)<<arr[i][j];
		}
		cout<<"\n";
	}
}
