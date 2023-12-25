#include<iostream>
#include<string>
using namespace std;
void sort_string(string* Code, string* Decode,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(Code[i].length()<Code[j].length()){
				string temp=Code[i];
				Code[i]=Code[j];
				Code[j]=temp;
				temp=Decode[i];
				Decode[i]=Decode[j];
				Decode[j]=temp;
			}
		}
	}
}
int main(){
	int n,found=-1;
	cin>>n;
	string Code[n],Decode[n],input,temp;
	for(int i=0;i<n;i++){
		cin>>input;
		Decode[i]=input.substr(0,1);
		Code[i]=input.substr(2);
	}
	sort_string(Code,Decode,n);
	cin>>temp;
	getline(cin,input);
	input=temp+input;
	for(int i=0;i<n;i++){
		do{
			found=input.find(Code[i],found+1);
			if(found!=-1){
				input=input.substr(0,found)+Decode[i]+input.substr(found+Code[i].length());
			}
		}while(found!=-1);
	}
	temp="";
	for(int i=0;i<input.length();i++){
		if(input[i-1]==' ' && input[i]==' ' && input[i+1]==' '){
			temp+=" ";
		}else if(input[i]!=' '){
			temp+=input[i];
		}
	}
	cout<<temp<<endl;
}
