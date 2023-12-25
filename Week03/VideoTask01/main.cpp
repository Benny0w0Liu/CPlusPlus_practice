#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;
void writing(string str){
	fstream myFile;
	myFile.open("text.txt",ios::out);//write
	for(int i=0;i<str.length();i++){
		if(myFile.is_open()){
			myFile<<(int)str[i]<<"\n";
		}
	}
	myFile<<10<<"\n";
	myFile.close();
}
void appending(string str){
	fstream myFile;
	myFile.open("text.txt",ios::app);//append
	for(int i=0;i<str.length();i++){
		if(myFile.is_open()){
			myFile<<(int)str[i]<<"\n";
		}
	}
	myFile<<10<<"\n";
	myFile.close();
}
void reading(){
	fstream myFile;
	myFile.open("text.txt",ios::in);//read
	string line;
	while(getline(myFile,line)){
		stringstream ss;
		int a;
		char ch;
		ss<<line;
		ss>>a;
		ch=a;
		cout<<ch;
	}
	myFile.close();
}
int main(){
	char choice='0';
	string str,temp;
	cout<<"e->exit\nw->Write the file\na->Append the file\nr->Read the file\n";
	while(choice!='e'){
		cout<<"Select next step:";
		cin>>choice;
		if(choice=='e'){
			break;
		}else if(choice=='w'){
			cout<<"Input your text:\n----------\n";
			cin>>temp;
			getline(cin,str);
			str=temp+str;
			writing(str);
			cout<<"----------\n\n";
		}else if(choice=='a'){
			cout<<"Input your text:\n----------\n";
			cin>>temp;
			getline(cin,str);
			str=temp+str;
			appending(str);
			cout<<"----------\n\n";
		}else if(choice=='r'){
			cout<<"The text in file:\n----------\n";
			reading();
			cout<<"----------\n\n";
		}
	}
	return 0;
} 
