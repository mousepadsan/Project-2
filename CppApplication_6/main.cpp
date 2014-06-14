/* 
 * File:   main.cpp
 * Author: Dale Rios
 * Created on June 8, 2014, 5:27 PM
 * Purpose: Project 2 (Text based game)
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

//Global Constants

//Function Prototypes
void title();//Title
void intro();//Story
void charInf(int, int);//character info
char slime();//Loot Drop
void plant(int, int);//plant monster
int btleCmd(int,int,int,int,int);//Commands
void prntCmd();//Print commands
//void dmgCalc1(int,int);//Damage calculator //not used
//void dmgCalc2(int,int);//Damage calculator //not used
void monAct(int,int);//Monster Action generator
int slmeAtk(int);//Slime Monster attack
int slmeHP(int);//Slime monster HP
void slmeEff(int &);//Slime's hidden power
void slmeEff2(int *);//Slime's hidden power

int main(int argc, char** argv) {
    //Random seed generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Variables
    int choice, choice2, col=5;
    int attack, crtStrk, guard, block;//Hero Actions
    int atkDmg, HP=50;//Hero damage and health
    int m1HP, m1Atk;// Monster(1) damage and health    
    int jeloCnc; //Chance of Jello lot being edible
    
    //title
    title();
    
    cout<<endl<<endl;
    
    //Story 
    intro();
    cout<<"What do you want to do?\n";
    cout<<"Enter the number of the command you want do.\n";
    m1HP=slmeHP(m1HP);
    do{
    prntCmd();
    cin>>choice;
    cout<<"\n";
    btleCmd(choice,attack,crtStrk,guard,block);//commands
    atkDmg=btleCmd(choice,attack,crtStrk,guard,block);//attack damage value
    m1HP-=atkDmg;  
    if(m1HP>0){
        cout<<"The monster only has "<<m1HP<<" HP left.\n\n";
        monAct(m1Atk,HP);
    }
    else{
        cout<<"The monster had fallen.\n";
    }
    }while(m1HP>0);
    
    cout<<"You have successfully defeated an extremely weak monster.\n"
            "Congratulations!\n";
    cout<<"The monster dropped some items on the floor.\n";
    cout<<"Jello: A Jello-like looking object. Might be edible.\n";
    cout<<"Dimension Transporter: A transporter so you can go back home.\n"; 
    jeloCnc=rand()%100+1;
    cout<<"What are you going to do with the items?\n";
    cout<<"1. Eat the jello.\n";    
    cout<<"2. Use the transporter to go home.\n";
    //ask for command
    cin>>choice2;
    if (choice2==1){
        slmeEff(choice2);
    }
    else if(choice2==2){
        slmeEff2(&choice2);
    }
    switch(choice2){
        case 1:{
            cout<<"Oh noes! Killing the slime gives a secret hidden effect.\n"; 
            cout<<"It made you eat the jello instead of using the transporter.\n";
            if(jeloCnc>1){
                cout<<"You died. Its not Jello.\n";
            }
            else if(jeloCnc=1){
                cout<<"Its jello.";
            }
        }break;
        case 2:{            
            cout<<"Oh noes! Killing the slime gives a secret hidden effect.\n";
            cout<<"It made you use the transporter instead of eating the Jello.\n";
            for(int i=0;col>i;i++){
                cout<<"*\n";
            }
            cout<<"You made it home safely.";
        }break;
    }
    return 0;
}

void slmeEff(int &a){
    a=2;
}

void slmeEff2(int *a){
    *a=1;
}

void monAct(int b,int c){
    b=rand()%5+1;
    int a;
    a=rand()%10+1;//Random Action Generator
    if(a<=2){
        cout<<"The monster is readying itself.\n";
    }
    else{
        cout<<"The monster attacked you for "<<b<<" damage.\n";
        cout<<"You only have "<<c<<" HP left.\n\n";
    }
}

void charInfo(int atk, int hp){
    cout<<"Attack Damage"<<setw(5)<<atk;
    cout<<"HP"<<setw(16)<<hp;
    
}

//void dmgCalc1(int hDmg,int mHP){
//    mHP-=hDmg;
//    
//    return mHP;
//}

//void dmgCalc2(int mDmg, int hHP){
//    hHP-=mDmg;
//    
//   return hHP;
//}

int slmeAtk(int atk1){
    atk1=rand()%3+1;
    
  return atk1;   
}

int slmeHP(int Hp1){
    Hp1=10;
    
    return Hp1;
}

void prntCmd(){
    cout<<"1. Attack: Attack the monster.\n";
    cout<<"2. Guard: Ready yourself for the monster's attack.\n";
}

int btleCmd(int a, int b, int c, int d, int e){
    int crit,blockRt;
    switch(a){
        case 1:{
            b=rand()%4+6;//Attack damage generator
            crit=rand()%100+1;
            if(crit<=10){//Crit hit chance 10%
                c=(b)*(2);
                cout<<"You attacked the monster.\n";
                cout<<"It's a critical hit.\n";
                cout<<"You did "<<c<<" damage to the monster\n";
            }
            else{
                cout<<"You attacked the monster.\n";
                cout<<"You did "<<b<<" damage to the monster\n";
            }
            
               }break;
        case 2:{
            d=rand()%5+1;//Monster damage reduce
            blockRt=rand()%100+1;//Block damage completely
            if(blockRt<=10){//Block chance 10%
               e=(d)*(50);               
            }
        }break;
        case 3:{
            charInfo(a,50);
        }break;
    }
    return b;
}

void intro(){
    cout<<"Press any key to start.\n";
    cin.ignore();
    
    cout<<"You're girlfriend just broke up with you and you're feeling depressed.\n";
    cout<<"Press any key to continue\n";
    cin.ignore();
    
    cout<<"You grabbed your phone and googled the nearest cliff in your area to finally end all of your suffering.\n";
    cout<<"Press any key to continue\n";    
    cin.ignore();    
    
    cout<<"You found the nearest and stiffest cliff in the area\n";
    cout<<"Press any key to continue\n";    
    cin.ignore();   
    
    cout<<"You started savoring the scenery as you about to take the plunge.\n";
    cin.ignore();
    
    cout<<"The perfect background music for this moment plays in your head.\n";
    cin.ignore();
    
    cout<<"-I used to think that could not go onnnnnnnnnnn-\n";
    cin.ignore();
    
    cout<<"You suddenly had a change of heart and have decided to live and move on.\n";
    cin.ignore();
    
    cout<<"-And life was nothing but an awful songggggg-\n";
    cin.ignore();
    
    cout<<"As you were turning around, the ground beneath your feet started crumbling down.\n";
    cout<<"-But now I know the meaning of true loveeeee-\n";       
    cin.ignore();
        
    cout<<"Just when you were about to fall of the cliff, you grabbed the roots of a nearby tree.\n";
    cout<<"-I'm leaning on the everlasting arms-\n";
    cin.ignore();
    
    
        
}

void title(){
    int col=81;
    int row=2;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){            
        cout<<"*";
        }cout<<endl;                   
    }
    cout<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
    <<endl<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
    <<endl<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
    <<endl<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Project     =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
    <<endl<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=      Rushed =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
    <<endl<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
    <<endl<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
            <<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){            
        cout<<"*";
        }cout<<endl;                   
    }
}