#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
void drawCircle(int radius,char (&arr)[21][21]) {
	int i=0,j=0;
    for (int y = -radius; y <= radius; y++) {
    	j=0;
        for (int x = -radius; x <= radius; x++) {
            if (fabs(x * x + y * y - radius * radius) < radius * 0.6) {
                arr[i][j]='*';
            }
            j++;
        }
        i++;
    }
}
int Clock_Orientation(int i,int j,int radius){
	double y=(double)radius-(double)i,x=(double)j-(double)radius;
	if(y==x && x==0){
		return 0;
	}else{
		if(y>=x && y<15*x/4){
			return 1;
		}else if(y<x && y>=4*x/15){
			return 2;
		}else if(y<4*x/15 && y>=0-4*x/15){
			return 3;
		}else if(y<0-4*x/15 && y>=0-x){
			return 4;
		}else if(y<0-x && y>=0-15*x/4){
			return 5;
		}else if(y<0-15*x/4 && y<=15*x/4){
			return 6;
		}else if(y<=x && y>15*x/4){
			return 7;
		}else if(y>x && y<=4*x/15){
			return 8;
		}else if(y>4*x/15 && y<=0-4*x/15){
			return 9;
		}else if(y>0-4*x/15 && y<=0-x){
			return 10;
		}else if(y>0-x && y<=0-15*x/4){
			return 11;
		}else if(y>=15*x/4 && y>0-4*x/15){
			return 12;
		}
	}
}
int Score(int x, int y, int radius){
	x=x-radius;
	y=y-radius;
	int ans=0;
	ans=11-sqrt(x*x+y*y);
	if(ans<=0){
		ans=0;
	}
	return ans;
}
int main() {
	char target[21][21];
    int radius=11,start,user_input[6][2];
    cin>>start;
    radius-=start;
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			target[i][j]=' ';
		}
	}
    drawCircle(radius,target);
    
	for(int i=0;i<6;i++){
		cin>>user_input[i][0]>>user_input[i][1];
		target[user_input[i][0]][user_input[i][1]]='+';
	}
	
	for(int i=0;i<radius*2+1;i++){
		for(int j=0;j<21;j++){
			if(i==radius && j-i>=0 && target[i][j]!='+'){
				if(j-i==0){
					cout<<" X";
				}else if(-j+i+radius+1>0){
					cout<<setw(2)<<11+i-j;
				}
				continue;
			}
			cout<<" "<<target[i][j];
		}
		cout<<"\n";
	}
	
	for(int i=0;i<6;i++){
		if(Score(user_input[i][0],user_input[i][1],radius)==11){
			cout<<i+1<<"->Direction:   |Score:  X"<<endl;
		}else if(Score(user_input[i][0],user_input[i][1],radius)<start){
			cout<<i+1<<"->Direction:"<<setw(3)<<Clock_Orientation(user_input[i][0],user_input[i][1],radius)<<"|Score:  M"<<endl;
		}else if(Score(user_input[i][0],user_input[i][1],radius)==10){
			cout<<i+1<<"->Direction:   |Score: 10"<<endl;
		}else{
			cout<<i+1<<"->Direction:"<<setw(3)<<Clock_Orientation(user_input[i][0],user_input[i][1],radius)<<"|Score:"<<setw(3)<<Score(user_input[i][0],user_input[i][1],radius)<<endl;
		}
	}
    return 0;
}

