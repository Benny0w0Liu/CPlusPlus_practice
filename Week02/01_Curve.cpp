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
        if (i+di<0 || i+di>=n || j+dj<0 || j+dj>=n || arr[i+di][j+dj]!=0) {
            if(di== 0 && dj== 1){
				di= 1;
				dj= 0;
			}else if(di== 1 && dj== 0){
				di= 0; 
				dj=-1;
			}else if(di== 0 && dj==-1){
				di=-1; 
				dj= 0;
			}else if(di==-1 && dj== 0) {
				di= 0; 
				dj= 1;
			}
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
