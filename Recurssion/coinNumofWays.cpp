#include<bits/stdc++.h>
using namespace std;



int solve(int *coins, int n,int target, int index)
{
    // base case
    if(target==0)
    {
        return 1;
    }
    if(target<0)
    {
        return 0;
    }

    int ways=0;
    for(int i=index; i< n;i++ )
    {
        ways +=solve(coins,n,target-coins[i],i);
        
    }
    return ways;
}
int main()
{
    int coins[]={1,2,3,4};
    int n=4;
    int target=5 ;


    cout<<solve(coins, n,target, 0);
}