#include<bits/stdc++.h>
using namespace std;

class Human
{
    private:
    int age;
    int gen;
    string name;

    public:

    int getAge()
    {
        return this->age;
    }
    void setAge(int age)
    {
        this->age=age;
    }
};

class female
{

};


int main()
{

    Human obj;

    obj.setAge(10);

    cout<<obj.getAge();


   

    
}