#include<bits/stdc++.h>
using namespace std;


//  Rec
int solve(string str1, string str2, int i, int j)
{
    if(i>= str1.size())
        return 0;
    
    if(j>=str2.size())
        return 0;
    
    int ans =0;
    // string char is match 
    if(str1[i] == str2[j])
    {
        ans = 1 + solve(str1,str2, i+1,j+1);
    }   
    else
    {
        ans = max(solve(str1,str2, i+1,j), solve(str1,str2, i,j+1));
    }

    return ans;
}

//  rec + mem
int solveMem(string str1, string str2, int i, int j, vector<vector<int>> &dp)
{
    if(i>= str1.size())
        return 0;
    
    if(j>=str2.size())
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans =0;
    // string char is match 
    if(str1[i] == str2[j])
    {
        ans = 1 + solveMem(str1,str2, i+1,j+1,dp);
    }   
    else
    {
        ans = max(solveMem(str1,str2, i+1,j,dp), solveMem(str1,str2, i,j+1,dp));
    }

    return dp[i][j] = ans;
}

// tabulation

int solveTab(string &str1, string &str2)
{
    // create dp vector
    vector<vector<int>>dp(str1.length()+1, vector<int>(str2.length()+1,0));
    vector<char> answer;
    for(int i=str1.length()-1; i>=0;i--)
    {
        for(int j= str2.length()-1; j>=0;j--)
        {
            int ans =0;
            // string char is match 
            if(str1[i] == str2[j])
            {
                ans = 1 + dp[i+1][j+1];
                answer.push_back(str1[i]);
            }   
            else
            {
                ans = max(dp[i+1][j], dp[i][j+1]);
            }

            dp[i][j] = ans;
        
        }
    }
    for(int i=0;i<dp.size()-1;i++)
    {
        for(int j=0;j<=dp[0].size()-1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Longest Common subsequence string is "<<endl;
      reverse(answer.begin(),answer.end());
    for(auto i : answer)
        cout<<i<<"";
  
    cout<<endl;
    return dp[0][0];
}

// SO in O(1)
int solveTabSO(string &str1, string &str2)
{
    // create dp vector
    // vector<vector<int>>dp(str1.length()+1, vector<int>(str2.length()+1,0));
    int m = str2.length();
    vector<int>curr(m+1,0);
    vector<int>next(m+1,0);

    for(int i=str1.length()-1; i>=0;i--)
    {
        for(int j= str2.length()-1; j>=0;j--)
        {
            int ans =0;
            // string char is match 
            if(str1[i] == str2[j])
            {
                ans = 1 + next[j+1];
            }   
            else
            {
                ans = max(next[j], curr[j+1]);
            }

            curr[j]= ans;
            
        }
        next = curr;
    }
    return next[0];
}

int main()
{
    string str1 ="abc";
    string str2 = "pbc";
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>>dp(n,vector<int>(m,-1));

    // cout<<"Ans is "<<solveMem(str1,str2, 0,0,dp)<<endl;
    cout<<solveTab(str1,str2);
    // cout<<"Ans Using tabulation SO Method "<<solveTabSO(str1,str2)<<endl;
}   