#include<bits/stdc++.h>
using namespace std;

int findWinner(int n,int k )
{

    cout<<"Start value of - > "<<n<<endl;
    
    if(n==1)
    {
        return 1;
    }
    else
    {
        // cout<<findWinner(n-1,k) + k-1;  
        // cout<<"Value of k - > "<<k<<endl;
        int a = (findWinner(n-1,k) + k-1 )%n+1;
        // cout<<"value of a "<<a<<endl;
        return a;
        // return a;
    }

}

int main()
{
    int n=6,k=5;

    cout<<findWinner(n,k);
}