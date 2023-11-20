#include<bits/stdc++.h>
#include<cstdlib>  
#include<map>
#include<ctime>  
#include<cctype>  
using namespace std;

class Rps
{
private:
    string player;
    char choice;
    char computer;
    int noofrounds;
    map<char,string> movenames;
public:
    Rps();

    ~Rps();
    
    void starGame();

    void getName();

    char getComp();

    void checkWinner(char,char);
};

Rps::Rps()
{
    movenames['r'] = "Rock";
    movenames['p'] = "Paper";
    movenames['s'] = "Scissor";
}

Rps::~Rps()
{
    cout<<"Game Over"<<endl;
}

void Rps:: starGame(){

    cout<<"Enter number of rounds : ";
    cin>>noofrounds;


    for (int i = 0; i < noofrounds; i++)
    {
        cout<<"ROUND "<<i+1<<":"<<endl;
        cout<<"Enter ['r'/'R'] to choose ROCK"<<endl;
        cout<<"Enter ['p'/'P'] to choose PAPER"<<endl;
        cout<<"Enter ['s'/'S'] to choose SCISSOR"<<endl;
        cout<<"Enter : ";
        cin>>choice;

        computer = getComp();

        checkWinner(tolower(choice),computer);
    }

}

char Rps:: getComp(){
    srand(time(0));  
    int n = (rand() % 3);
    if(n==0)
    {
        return 'r';
    }else if(n==1)
    {
        return 'p';
    }
    else{
        return 's';
    }    
    return 'a';
}

void Rps::checkWinner(char p,char c){
    if(p==c){
        cout<<"It Was a Draw you both choosed "<<movenames[p] <<endl;
        return;
    }

    if(p=='r'){
        if(c =='p'){
            cout<<"You Lost! you played "<<movenames[p]<<" computer played "<<movenames[c]<<endl;
        }else{
            cout<<"You Won! you played "<<movenames[p]<<" computer played "<<movenames[c]<<endl;
        }
    }
    else if(p=='p'){
        if(c =='s'){
            cout<<"You Lost! you played "<<movenames[p]<<" computer played "<<movenames[c]<<endl;
        }else{
            cout<<"You Won! you played "<<movenames[p]<<" computer played "<<movenames[c]<<endl;
        }
    }else if(p=='s'){
        if(c =='r'){
            cout<<"You Lost! you played "<<movenames[p]<<" computer played "<<movenames[c]<<endl;
        }else{
            cout<<"You Won! you played "<<movenames[p]<<" computer played "<<movenames[c]<<endl;
        }
    }
}


int main(){

    Rps obj;
    obj.starGame();

    return 0;
}