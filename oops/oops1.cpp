#include<bits/stdc++.h>
using namespace std;

class Human
{
    // Data Membars

    public:
    int age;
    char gender;
   

    // member Functions

    // int getAge()
    // {
    //     return age;
    // }

    // void setAge(int a)
    // {
    //     age = a;
    // }

    // int getGender()
    // {
    //     return gender;
    // }

    // void setGender(char ch)
    // {
    //     gender = ch;
    // }


    // Create A Contructor

    // Human()
    // {
    //     cout<<"I am a Constructor"<<endl;
    //     age =50;
    //     gender='f';
    // }


    // Parameterized constructor

    Human(int age, int gender)
    {
        cout<<"I m in P constructor"<<endl;
        this -> age = age;
        this -> gender = gender;

    }



    // Cereate our OWn copy COnstructor

    
// copy constructor
    Human (Human &temp)
    {
        this->age= temp.age;

    }

    
};

int main()
{
    cout<<"Sab Sahi chal Raha hai"<<endl;


    // Human obj1 ;


    // cout<<sizeof(obj1)<<endl;


    // // obj1.age=10;
    // // obj1.gender='f';

    // // cout<<obj1.age<<" "<<obj1.gender<<endl;



    // Static

    // Human a;
  
    // cout<<a.age<<endl;
    // cout<<a.gender<<endl;

    // dyanamic

    // Human *obj = new Human;

    // cout<<obj->age<<endl;
    // cout<<obj->gender<<endl;





    // parameterized constructor object
    int age = 100;
    int gender = 'f';

    Human *obj2 = new Human(age, gender);


    cout<<obj2->age<<" "<<obj2->gender<<endl;



    // default Copy COnstructor

    // Human *obj4(obj2);

    // cout<<obj4->age<<" "<<obj4->gender<<endl;


    //our Copy Cons

    Human *suresh(obj2);

    cout<<suresh->age<<" "<<suresh->gender<<endl;

    


    return 0;
}