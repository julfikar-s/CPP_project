#include<iostream>
#include <vector>
#include<string>
#include<cmath>
int uid=1000000;
using namespace std;
struct customer
{
    int id;
    string name;
    int balance;
};
void newc(vector<customer> &x, int *y);
int main()
{
    vector <customer> c;
    while(true)
    {
        string cmd;
        cin>>cmd;
        if(cmd=="new"){
            newc(c,&uid);
        }
        cout<<c[0].id<<endl<<c[0].name<<endl;
    }

}
void newc(vector<customer> &x, int *y)
{
    customer c2;
    c2.id=*(y++);
    cin>>c2.name;
    x.push_back(c2);
}