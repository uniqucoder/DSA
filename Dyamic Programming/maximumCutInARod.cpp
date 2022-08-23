#include<bits/stdc++.h>
using namespace std;

int solve(int n, int a, int b, int c)
{
    if(n==0)
    {
        return 0;
    }
    if(n < 0)
        return INT_MIN;

    int first = solve(n-a,a,b,c);
    int second = solve(n-b,a,b,c);
    int third = solve(n-c,a,b,c);

    return 1 + max(first,max(second,third));
}

int solveMem(int n, int a, int b, int c,vector<int>&dp)
{
    if(n==0)
    {
        return 0;
    }
    if(n < 0)
        return INT_MIN;

    if(dp[n] != -1)
    {
        return dp[n];
    }

    int first = solveMem(n-a,a,b,c,dp);
    int second = solveMem(n-b,a,b,c,dp);
    int third = solveMem(n-c,a,b,c,dp);

    return dp[n] = 1 + max(first,max(second,third));
}

int solveTab(int nthTerm, int a,int b,int c)
{
    // create dp array
    vector<int> dp(nthTerm +1, INT_MIN);

    dp[0] = 0;

    for(int n = 1; n<=nthTerm; n++)
    {
        int first = dp[n-a];
        int second = dp[n-b];
        int third = dp[n-c];
        dp[n] = 1 + max(first,max(second,third));
    }
    cout<<dp[nthTerm];
    cout<<endl;
    return dp[nthTerm];
}

int main()
{
    int n =17;
    int a = 10;
    int b = 11;
    int c =3;

    // step1: create Dp vector
    vector<int>dp(n+1,-1);

    // cout<< solveMem(n,a,b,c,dp)<<endl;

    cout<<solveTab(n,a,b,c)<<endl;
}