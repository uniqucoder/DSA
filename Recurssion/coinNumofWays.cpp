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
    int coins[]={1,2};
    int n=2;
    int target=4 ;


    cout<<solve(coins, n,target, 0);
}