#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> numbers;
	numbers.push_back(0);
	
	for(int i=1;i<=10;i++){
		numbers.push_back(i);
	}
	
	for(int number : numbers){
		cout<<number<<" ";
	}
	cout<<"\n";
	
	//insert
	numbers.insert(numbers.begin()+5,88);
	//erase
	numbers.erase(numbers.begin()+3);
	//pop_back
	numbers.pop_back();
	//iterator 
	for(auto it=numbers.begin();it!=numbers.end();it++){
		cout<<*it<<" ";
	}
	
	return 0;
}
