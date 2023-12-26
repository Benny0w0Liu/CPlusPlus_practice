#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;
bool finding(vector<int> arr, int a){
	for(int i=0;i<arr.size();i++){
		if(arr[i]==a){
			return 1;
		}
	}
	return 0;
}

int main(){
	srand( time(NULL) );
	vector<string> name;
	fstream text;
	text.open("Name.txt",ios::in);
	string line;
	while(getline(text,line)){
		name.push_back(line);
	}
	text.close();
	//Fourth Prize
	cout<<"Fourth Prize:"<<endl;
	vector<int> Fourth,Third,Second;
	for(int i=0;i<10;i++){
		Fourth.push_back(rand()%(name.size()));
	}
	for(int i=0;i<10;i++){
		cout<<i+1<<":"<<name[Fourth[i]]<<endl;
	}
	cout<<"\n";
	//Third Prize'
	cout<<"Third Prize:"<<endl;
	for(int i=0;i<6;i++){
		Third.push_back(rand()%(name.size()));
	}
	for(int i=0;i<6;i++){
		cout<<i+1<<":"<<name[Third[i]]<<endl;
	}
	cout<<"\n";
	//Second Prize
	cout<<"Second Prize:"<<endl;
	for(int i=0;i<2;i++){
		Second.push_back(rand()%(name.size()));
	}
	for(int i=0;i<2;i++){
		cout<<i+1<<":"<<name[Second[i]]<<endl;
	}
	cout<<"\n";
	//First Prize
	int First=rand()%(name.size());
	cout<<"First Prize:"<<endl;
	cout<<name[First]<<"!\n";
	
	fstream result;
	result.open("Result.txt",ios::out);
	for(int i=0;i<name.size();i++){
		result<<name[i];
		if(i==First){
			result<<",Polaroid";
		}if(finding(Second,i)){
			result<<",Champagne";
		}if(finding(Third,i)){
			result<<",Exchange coupon";
		}if(finding(Fourth,i)){
			result<<",Red Bull";
		}
		result<<"\n";
	}
	result.close();
	
	return 0;
}
