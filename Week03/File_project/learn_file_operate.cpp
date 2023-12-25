#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	fstream myFile;
	myFile.open("test.txt",ios::out);//write
	if(myFile.is_open()){
		myFile << "Hello\n";
		myFile << "This is second line.\n";
	}
	myFile.close();
	
	myFile.open("test.txt",ios::app);//append
	if(myFile.is_open()){
		myFile << "Hello2\n";
	}
	myFile.close();
	
	string file_str="";
	myFile.open("test.txt",ios::in);//read
	if(myFile.is_open()){
		string line;
		while (getline(myFile, line)){
			file_str+=line+"\n";
		}
	}
	cout<< file_str;
	myFile.close();
	
	return 0; 
}
