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
 

};

class Hero : virtual public Bike
{
    public:
   
    
};

class HeroHonda : public Honda, public Hero
{

};

int main()
{
    HeroHonda obj;
    obj.getDetails();
}