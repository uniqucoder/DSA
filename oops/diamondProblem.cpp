#include<bits/stdc++.h>
using namespace std;

class Bike
{
    public:

    string type;
     void getDetails()
    {
        cout<<"Iam in Bike"<<endl;
    }
};

class Honda:virtual public Bike
{
    public:
    void getDetails()
    {
        cout<<"Iam in Honda"<<endl;
    }
   

};

class Hero : virtual public Bike
{
    public:
    void getDetails()
    {
        cout<<"Iam in Hero"<<endl;
    }
    
};

class HeroHonda : public Honda, public Hero
{

};

int main()
{
    HeroHonda obj;
    obj.getDetails();
}