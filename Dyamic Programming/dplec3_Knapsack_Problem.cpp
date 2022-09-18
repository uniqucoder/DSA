#include<bits/stdc++.h>
using namespace std;


int knapsack(vector<int>val, vector<int>&wt, int index, int capacity)
{
    // base case
    if(index >= val.size() || capacity == 0)
        return 0;

    int incl = 0;
    if(capacity >= wt[index])
        incl = val[index] + knapsack(val,wt, index+1, capacity - wt[index]);
    
    int excl = 0 + knapsack(val,wt,index+1,capacity);

    return max(incl,excl);
} 

// rec + mem

int solve(vector<int>val, vector<int>&wt, int index, int capacity, vector<vector<int>>&dp)
{
   // base case
    if(index >= val.size() || capacity == 0)
        return 0;

    if(dp[index][capacity] != -1)
        return dp[index][capacity];
    int incl = 0;
    if(capacity >= wt[index])
        incl = val[index] + solve(val,wt, index+1, capacity - wt[index],dp);
    
    int excl = 0 + solve(val,wt,index+1,capacity,dp);

    return dp[index][capacity]=max(incl,excl); 
}


// Tabulation 

int solveTab(vector<int>&val, vector<int>&wt, int n, int C)
{
    // step 1 Create Dp vector
    vector<vector<int>>dp(n+1, vector<int>(C+1, 0));

    for(int index = n-1; index>=0;index--)
    {
        for(int capacity = 0; capacity<=C;capacity++)
        {
            int incl = 0;
            if(capacity >= wt[index])
                incl = val[index] + dp[index+1][capacity - wt[index]];
            
            int excl = 0 + dp[index+1][capacity];

            dp[index][capacity]=max(incl,excl); 
        }
    }

    return dp[0][C];
}

int main()
{
    vector<int>val,wt;
    val.push_back(60);
    val.push_back(100);
    val.push_back(120);


    wt.push_back(10);
    wt.push_back(20);
    wt.push_back(30);
    int capacity = 50;

    // cout<<knapsack(val, wt,0, capacity);

    //  rec + mem
    int n = 3;
    vector<vector<int> > dp(n+1,vector<int>(capacity+1,-1));
    

    cout<<"Ans is  "<<solve(val,wt,0, capacity,dp)<<endl;

    // cout<<"Ans using Tabulation "<<solveTab(val, wt, n, capacity)<<endl;

 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=capacity;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    

}