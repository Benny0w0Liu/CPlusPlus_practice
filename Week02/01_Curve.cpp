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
	for(int i=n;i>0;i--){
		if(i!=n){
			for(int j=0;j<i;j++){
				switch(direction%4){
					case 0:
						x++;
						break;
					case 1:
						y++;
						break;
					case 2:
						x--;
						break;
					case 3:
						y--;
						break;
				}
				arr[y][x]=user[count];
				count++;
			}
			direction++;
			for(int j=0;j<i;j++){
				
				switch(direction%4){
					case 0:
						x++;
						break;
					case 1:
						y++;
						break;
					case 2:
						x--;
						break;
					case 3:
						y--;
						break;
				}
				arr[y][x]=user[count];
				count++;
			} 
			direction++;
		}else{
			for(int j=0;j<i;j++){				
				switch(direction%4){
					case 0:
						x++;
						break;
					case 1:
						y++;
						break;
					case 2:
						x--;
						break;
					case 3:
						y--;
						break;
				}
				arr[y][x]=user[count];
				count++;
			}
			direction++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<setw(3)<<arr[i][j];
		}
		cout<<"\n";
	}
}
