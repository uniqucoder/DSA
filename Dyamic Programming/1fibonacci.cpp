#include<bits/stdc++.h>
using namespace std;

// RECURSION
// TC exponential 2^n
int getFibo(int n)
{

    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }

    return getFibo(n-1)+getFibo(n-2);
}

// recursion + mem
// step 1 : create Dp array and pass to the function
// step2 : Store the answer in Dp array
//step3 : if ans present in DP array if yes then return -> just after the base cases
// Tc O(n) sC O(n) + dp(n)
int getFiboMem(int n,vector<int>&dp)
{

    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    // step3:
    if(dp[n] != -1)
    {
        return dp[n];
    }

    int ans = getFiboMem(n-1,dp)+getFiboMem(n-2,dp);
    //step2:

    return dp[n] = ans;
}

// Bottop up approch
// step 1 : create Dp array
//step2 : base case analysis of rec and update the Dp array
// step 3: find the range for changing the varibles and copy the the logic of recc code
// TC - O(N)
int solveTab(int nthTerm)
{
    // step1:
    vector<int> dp(nthTerm+1,0);

    // step2:
    dp[0] = 0;
    dp[1] = 1;

    // step3
    for(int n=2; n<=nthTerm; n++)
    {
        int ans = dp[n-1] + dp[n-2];
        dp[n] = ans;
    }

    return dp[nthTerm];
}


//space optimization



int main()
{
    int n;
    cout<<"Enter the  value of n"<<endl;
    cin>>n;

    // step1:

    // vector<int>dp(n+1,-1);
    int ans = solveTab(n);

    cout<<"Ans is => "<<ans<<endl;
}