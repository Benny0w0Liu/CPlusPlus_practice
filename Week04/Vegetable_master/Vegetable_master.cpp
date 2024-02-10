#include<iostream>
#include<string>
#include<iomanip> 
#include<vector>
using namespace std;
struct Vegetable
{
    string Breed;
    int Time_required;
    double Prize;
};
Vegetable setVeg(string b,int t, double p){
    Vegetable veg;
    veg.Breed=b;veg.Time_required=t;veg.Prize=p;
    return veg;
}
class Field{
public:
    Vegetable vegetable;
    int Days;
    bool Nutrient;
    Field(){
        vegetable.Breed="_";
        vegetable.Time_required=0;
        vegetable.Prize=0.0;
        Days=0;
        Nutrient=0;
    }
    void Sowing(Vegetable veg){
        vegetable=veg;
        Days=0;
    }
    void Turn_changes(){
        if(this->Days==vegetable.Time_required && vegetable.Breed!="_"){
            vegetable.Breed+="+";
        }
        if(this->Days>=vegetable.Time_required*1.5 && vegetable.Breed!="_"){
            vegetable=setVeg("_",0,0.0);
            Days=0;
            Nutrient=1;
        }
		if(vegetable.Breed!="_"){
            Days++;
        }
    }
    Vegetable Harvest(){
        Vegetable harvest;
        string breed=vegetable.Breed;
        double prize=vegetable.Prize;
        if(Nutrient==1){
            breed+="*";
            prize=prize*1.5;
            harvest=setVeg(breed,0,prize);
        }else{
            harvest=setVeg(breed,0,prize);
        }
        if(Days<vegetable.Time_required){
            harvest.Prize=harvest.Prize*0.5;
        }
        Days=0;
        Nutrient=0;
        vegetable=setVeg("_",0,0.0);
        return harvest;
    }
};
class Player
{
public:
    vector<Vegetable> Bag;
    int pos_i,pos_j;
    string Name;
    double Total;
    Player(string name){
        Name=name;
        pos_i=4;
        pos_j=0;
        Total=0;
    }
    void Move(char Direction){
        switch (Direction)
        {
        case 'u':
            pos_i--;
            break;
        case 'd':
            pos_i++;
            break;
        case 'l':
            pos_j--;
            break;
        case 'r':
            pos_j++;
            break;
        default:
            break;
        }
        if(pos_i<0){
            pos_i=0;
        }
        if(pos_i>4){
            pos_i=4;
        }
        if(pos_j<0){
            pos_j=0;
        }
        if(pos_j>4){
            pos_j=4;
        }
    }
    void Harvest(Vegetable new_veg){
        if(Bag.size()<=10){
            Bag.push_back(new_veg);
        }else{
            Bag.pop_back();
            Bag.push_back(new_veg);
        }
    }
    void Sale(){
        for(int i=0;i<Bag.size();i++){
            Total+=Bag[i].Prize;
        }
        Bag.clear();
    }
    void Check(){
        cout<<"Position : ( "<<pos_j+1<<" , "<<5-pos_i<<" )"<<endl;
        cout<<"Bag : "<<endl;
        for(int i=0;i<Bag.size();i++){
            cout<<Bag[i].Breed<<"|"<<Bag[i].Prize<<endl;
        }
        cout<<"Total : "<<Total;
    }
};
void Draw_field(Field (&arr)[5][5], Player p){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==p.pos_i && j==p.pos_j){
                cout<<setfill('_')<<setw(15)<<left<<p.Name<<" ";
            }else{
                cout<<setfill('_')<<setw(15)<<"_"<<" ";
            }
        }
        cout<<"\n";
        for(int j=0;j<5;j++){
            cout<<setfill('_')<<setw(15)<<left<<arr[i][j].vegetable.Breed <<" ";
        }
        cout<<"\n";
        for(int j=0;j<5;j++){
            cout<<"Day : "<<setfill('_')<<setw(9)<<left<<arr[i][j].Days <<" ";
        }
        cout<<"\n";
        for(int j=0;j<5;j++){
            string pos="Pos : (";
            pos+='0'+j+1;
            pos+=",";
            pos+='0'+5-i;
            pos+=")";
            cout<<setfill('_')<<setw(15)<<pos<<" ";
        }
        cout<<"\n";
        for(int j=0;j<5;j++){
            if(arr[i][j].Nutrient==0){
                cout<<setfill('_')<<setw(15)<<"_"<<" ";
            }else{
                cout<<setfill('*')<<setw(15)<<left<<"*"<<" ";
            }
        }
        cout<<"\n";
        cout<<"\n";
    }
}
int main(){
    Vegetable Breeds[4];
    string name; 
    Breeds[0]=setVeg("_",0,0);
    Breeds[1]=setVeg("Cucumber",2,9.9);
    Breeds[2]=setVeg("Tomato",4,15.0);
    Breeds[3]=setVeg("Ginger",6,99.9);
    Field field[5][5];
    cout<<"Input your user name : ";
    cin>>name;
    
    Player user = Player(name);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            field[i][j]=Field();
        }
    }
    int Day=0;
    while(Day<101){
        cout<<"Day : "<<Day<<"/100"<<endl;
        Draw_field(field,user);
        
        int choice;
        char ch;
        cout<<"Input your choice>> 1.Moving 2.Sowing 3.Harvest 4.Sale 5.Skip"<<endl;
        cin>>choice;
        if(choice==1){
            cout<<"Input your Direction>> u.Up d.Down l.Left r.Right"<<endl;
            cin>>ch;
            user.Move(ch);
        }else if(choice==2){
            cout<<"Input your breeds>>"<<endl;
            for(int i=0;i<4;i++){
                cout<<i<<". Breed : "<<Breeds[i].Breed<<", Time required : "<<Breeds[i].Time_required<<", Prize : "<<Breeds[i].Prize<<endl;
            }
            cin>>choice;
            field[user.pos_i][user.pos_j].Sowing(Breeds[choice]);
        }else if(choice==3){
            Vegetable vegt;
            user.Harvest(field[user.pos_i][user.pos_j].Harvest());
        }else if(choice==4){
            user.Sale();
        }
        Day++;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                field[i][j].Turn_changes();
            }
        }
        user.Check();
        cout<<"\ninput any character to go to next day >>";
        cin>>ch;
        system("cls");
    }
    char cha;
    cout<<"Total : "<<user.Total<<endl;
    cout<<"\ninput any character to exit>>";
    cin>>cha;
    return 0;
}