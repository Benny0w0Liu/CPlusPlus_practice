#include <iostream>
using namespace std;
int main(){
	int size;
	cin>>size;
	float month[size];//={100,220,300,0,200,250};
	float total = 0;
	for(int i=0;i<12;i++){
		cout<<i+1<<".";
		cin>>month[i];
		total+=month[i];
	}
	cout<<"total :¡@"<<total<<endl;
	cout<<"average :¡@"<<total/12<<endl;
	cout<<"inTwoYears :¡@"<<total*2<<endl;
}
