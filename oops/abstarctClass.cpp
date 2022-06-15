#include<bits/stdc++.h>
using namespace std;

class Shape
{
    private:

    virtual void area() = 0;
};

class Square:public Shape
{
    void area()
    {
        cout<<"I am in Sqaure"<<endl;
    }
};


class triangle : public Shape
{
    public:
    void area()
    {
        cout<<"I am in triangle"<<endl;
    }
};

class Circle: public Shape
{
    public:
   void area()
    {
        cout<<"I am in Circle"<<endl;
    }
};


int main()
{
    Circle C;
    
    triangle :: area();
    


}