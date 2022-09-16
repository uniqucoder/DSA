#include<bits/stdc++.h>
using namespace std;

// rec solution
int solve(int n)
{
    if(n==0)
        return 0;
    
    int ans = INT_MAX;

    for(int i=1;i*i <= n;i++)
    {
        ans = min(ans, 1+solve(n-(i*i)));
    }
    return ans;
}

// Rec + MEM
int solveMem(int n, vector<int>&dp)
{
    if(n==0)
        return 0;
    
    
    if(dp[n] != -1)
        return dp[n];
    int ans = INT_MAX;
    for(int i=1;i*i <= n;i++)
    {
        ans = min(ans, 1+solve(n-(i*i)));
    }
    return dp[n] = ans;
}

// Tabulation

int solveTab(int N)
{
    // create Dp vector
    vector<int>dp(N+1,0);
    for(int n=1;n<=N;n++)
    {
        int ans = INT_MAX;
        for(int i=1;i*i <= n;i++)
        {
            ans = min(ans, 1+dp[n-(i*i)]);
        }
        dp[n] = ans;
    }
    return dp[N];
}
int main()
{
    int n =13;
    // cout<<"hello "<<endl;
    // cout<<"ANS is "<<solve(n)<<endl;

    // vector<int>dp(n+1,-1);

    // cout<<solveMem(n,dp)<<endl;

    cout<<"Ans is "<<solveTab(n)<<endl;
}