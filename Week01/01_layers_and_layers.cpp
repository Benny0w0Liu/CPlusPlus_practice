#include<iostream>
using namespace std; 
int main() 
{
    int n,i,j;
    cin>>n;
    for(i=1-n;i<n;i++){
        for(j=1-n;j<n;j++){
        	int a=i,b=j;
        	if(i<0){
        		a=-i;
			}
			if(j<0){
				b=-j;
			}
            if(a>b){
                cout<<a+1<<" ";
            }else{
                cout<<b+1<<" ";
            }   
        }
        cout<<"\n";
    }
    return 0;
}
