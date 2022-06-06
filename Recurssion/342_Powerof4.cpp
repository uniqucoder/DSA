// 342 Find Power of 4 is true or false using recurssion

#include<bits/stdc++.h>
using namespace std;

bool solve(int n,int index,int num)
{
//     base case
    if(pow(num,index)== n)
    {
        return true;
    }
    else if(pow(num,index) > n)
    {
        return false;
    }
    return solve(n,index+1,num);
    
    
    
}

int main()
{
    int n=16;
    int index=0;
        int num=4;
        cout<< solve(n,index,num);
}