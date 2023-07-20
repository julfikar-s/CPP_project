#include<iostream>
#include <random>
using namespace std;
int random_n();
int level=1;
void game(int number, int level);
void task(int n, int *level, bool *cmd);
int menu();
int main()
{
    system("cls");
    cout<<"Welcome to number Guessing Game\n\n";
    bool con=true;
    while (con)
    {
        task(menu(), &level, &con);

    }
}
int random_n()
{   int val = rand()%11;
    random_device r;
    mt19937 eng(r());
    uniform_int_distribution<> distr(1,10);
    return distr(eng);
}
void game(int number, int level)
{
    int n;
    if(level==1)
    {
        n=5;
    }
    else if(level==2)
    {
        n=3;
    }
    else if (level==3)
    {
        n=2;
    }
    cout<<"Guess a Number btween 1-10 :"<<endl;
    for(int i=1; i<=n; i++)
    {
        int guess;
        cin>>guess;
        if(guess>number&&guess>=1&&guess<=10)
        {
            cout<<"<< Lower"<<endl;
        }
        else if(guess<number&&guess>=1&&guess<=10)
        {
            cout<<">> Upper"<<endl;
        }
        else if(guess==number) 
        {
            cout<<"Congratulation You won The Game!!!"<<endl;
            return;
        }
        else
        cout<<"Number Out of Limits"<<endl;
    }
    cout<<"Correct Number Is :"<<number<<endl<<"Good Luck For Your Next Game!"<<endl;
}
int menu()
{
    cout<<"Play  : 1\nLevel : 2\nExit  : 3\n";
    cout<<"Please Choose From Menu : ";
    int test;
    cin>>test;
    system("cls");
    return test;
}
void task(int n, int *level, bool *cmd){
    if(n==1){
        bool cmd=true;
        while(cmd){
            game(random_n(),*level);
            cout<<"Do You Want To Play Again : "<<endl;
            cout<<"Yes : 1\nNo  : 0\n";
            int x=0;
            cin>>x;
            if(x==0)
            cmd=false;
            system("cls");
        }
    }
    if(n==2)
    {
        cout<<"Easy\t: 1(\"5 Chances\")\nMedium\t: 2(\"3 Chances\")\nHard\t: 3(\"2 Chances\")"<<endl;
        cout<<"Please Choose a level: ";
        int l;
        cin>>l;
        if(l>=1&&l<=3)
        *level=l;
        system("cls");
    }
    if(n==3){
        *cmd=false;
    }
}