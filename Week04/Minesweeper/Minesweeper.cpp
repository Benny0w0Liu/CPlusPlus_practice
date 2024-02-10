#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

class block{
public:
	bool visiblity;
	bool is_bomb;
	bool flag;
	int bombs_around;
	block(){
		visiblity=0;
		is_bomb=0;
		flag=0;
		bombs_around=0;
	}
};

block arr[18][32];
bool run=1,win=0;
int width,height,bombs=0;
int around[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
void print(){
	system("CLS");
	for(int i=0;i<height+1;i++){
		if(i==0){
			cout<<"+ ";
		}else{
			char ch='A'+i-1;
			cout<<"\n"<<ch<<" ";
		}
		for(int j=1;j<width+1;j++){
			if(i==0){
				cout<<setw(2)<<j;
			}else if(arr[i][j].visiblity==1){
				cout<<" "<<arr[i][j].bombs_around;
			}else if(arr[i][j].flag==0){
				cout<<" _";
			}else{
				cout<<" f";
			}
		}
	}
	cout<<endl;
}

void logic(){
	bool f=0;
	for(int i=1;i<height+1;i++){
		for(int j=1;j<width+1;j++){
			if(arr[i][j].visiblity==1 && arr[i][j].is_bomb==1){
				run=0;
				win=0;
				return;
			}
			if(arr[i][j].visiblity==0 && arr[i][j].is_bomb==0){
				f=1;
			}
		}
	}
	if(f==0){
		run=0;
		win=1;
	}
	while(1){
		f=1;
		for(int i=1;i<height+1;i++){
			for(int j=1;j<width+1;j++){
				if(arr[i][j].visiblity==1 && arr[i][j].bombs_around==0){
					for(int k=0;k<8;k++){
						if(arr[i+around[k][0]][j+around[k][1]].visiblity==0){
							f=0;
							arr[i+around[k][0]][j+around[k][1]].visiblity=1;
						}
					}
				}
			}
		}
		if(f==1){
			break;
		}
	}
	
		
}
void setUp(){
	int difficulty=0;
	while(difficulty<=0 || difficulty>3){
		system("CLS");
		cout<<"Input your difficulty:\n\t\tHeight\tWidth\tMines\n1.Beginner\t9\t9\t10\n2.Intermediate\t16\t16\t40\n3.Expert\t16\t30\t99"<<endl;	
		cout<<"Your input:\t";	
		cin>>difficulty;
	}
	system("CLS");
	switch(difficulty){
		case 1:
			width=9;height=9;bombs=10;
			break; 
		case 2:
			width=16;height=16;bombs=40;
			break; 
		case 3:
			width=30;height=16;bombs=99;
			break; 
	}
	for(int i=0;i<18;i++){
		for(int j=0;j<32;j++){
			arr[i][j]=block();
		}
	}
	int bombpos[height*width];
	for(int i=0;i<height*width;i++){
		bombpos[i]=i;
	}
	for(int i=0;i<bombs;i++){
		int r=rand()%(height*width-i)+i;
		swap(bombpos[i],bombpos[r]);
	}
	for(int i=0;i<bombs;i++){
		arr[bombpos[i]/height+1][bombpos[i]%width+1].is_bomb=1;
	}
	for(int i=0;i<height+1;i++){
		for(int j=0;j<width+1;j++){
			for(int k=0;k<8;k++){
				arr[i][j].bombs_around += (int)arr[i+around[k][0]][j+around[k][1]].is_bomb;
			}
		}
	}
	print();
	char row;
	int col;
	cout<<"Reveal your first block!\ninput the row(e.g. A,B..):	";
	cin>>row;
	cout<<"input the column(e.g. 1,2..):	";
	cin>>col;
	arr[int(row-'A')+1][col].visiblity=1;
	for(int k=0;k<8;k++){
		if(arr[int(row-'A')+1+around[k][0]][col+around[k][1]].is_bomb==0){
			arr[int(row-'A')+1+around[k][0]][col+around[k][1]].visiblity=1;
		}
	}
	logic();
}
void input(){
	char row;
	int col,m;
	cout<<"input the row(e.g. A,B..):	";
	cin>>row;
	cout<<"input the column(e.g. 1,2..):	";
	cin>>col;
	cout<<"input the movement\n1->flag it\n2->reveal it\nYour input:\t";
	cin>>m;
	if(m==1){
		if(arr[int(row-'A')+1][col].flag==1){
			arr[int(row-'A')+1][col].flag=0;
		}else{
			arr[int(row-'A')+1][col].flag=1;
		}
		return;
	}
	if(m==2){
		arr[int(row-'A')+1][col].visiblity=1;
		return;
	}
}
int main(){
	srand(time(NULL));
	setUp();
	while(run){
		logic();
		print();
		if(win==0){
			input();
		}
		logic();
	}
	if(win==1){
		cout<<"win:D";
	}else{
		system("CLS");
	 	for(int i=0;i<height+1;i++){
			if(i==0){
				cout<<"+ ";
	 		}else{
	 			char ch='A'+i-1;
	 			cout<<"\n"<<ch<<" ";
	 		}
	 		for(int j=1;j<width+1;j++){
	 			if(i==0){
	 				cout<<setw(2)<<j;
	 			}else{  
					if(arr[i][j].is_bomb){
						cout<<" *";
					}else{
						cout<<" "<<arr[i][j].bombs_around;
					}
	 			}
	 		}
	 	}
	 	cout<<endl;
		cout<<"lose:(";
	}
	return 0;
}
