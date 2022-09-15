#include<bits/stdc++.h>
using namespace std;

// Recursive solution

int getMin(vector<int>arr, int target)
{
    if(target == 0)
        return 0;
    
    if(target < 0)
        return INT_MAX;
    
    int mini = INT_MAX;

    for(int i=0;i<arr.size();i++)
    {
        int ans = getMin(arr, target - arr[i]);
        // If ans is valid then update ans
        if(ans != INT_MAX)
            mini = min(1+ans, mini);
    }

    return mini;
}

// rec + mem

int solveMem(vector<int>arr, int target, vector<int>&dp)
{
    if(target == 0)
        return 0;
    if(target < 0) 
        return INT_MAX;
    if(dp[target] != -1)
        return dp[target];

    int mini = INT_MAX; 
    for(int i=0;i<arr.size();i++)
    {
        int ans = solveMem(arr, target - arr[i], dp);

        if(ans != INT_MAX)
            mini = min(1+ans, mini);

    }
    return dp[target] = mini;
}

// Tabulation method

int solveTab(vector<int>arr,int t)
{
    // create Dp vector
    vector<int>dp(t+1,INT_MAX);

    // Analyse the base case of recursion do changes in dp array
    dp[0] = 0;

    for(int target=1; target<=t; target++ )
    {
        int mini = INT_MAX; 
        for(int i=0;i<arr.size();i++)
        {
            if(target-arr[i] >= 0)
            {
                int ans = dp[target - arr[i]];
            
                if(ans != INT_MAX)
                    mini = min(1+ans, mini);
            }
            

        }
        dp[target] = mini;
    }

    return dp[t];
}
int main()
{
    vector<int>arr= {1,2,5};
    int target = 11;
    vector<int>dp(target+1,-1);
    // int ans = solveMem(arr, target,dp);
    // if(ans == INT_MAX)
    //     cout<<"-1"<<endl;
    // else
    //     cout<<"Minimum no of coins requird  "<<ans<<endl;


    cout<<solveTab(arr,target)<<endl;
}