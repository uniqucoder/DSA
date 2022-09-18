#include<bits/stdc++.h>
using namespace std;

// rec
int solve(vector<vector<int>>&matrix ,int i, int j, int &maxi)
{
    if(i>=matrix.size() || j>= matrix[0].size())
        return 0;
    
    int right = solve(matrix, i,j+1,maxi);
    int diagonal = solve(matrix, i+1,j+1,maxi);
    int bottom = solve(matrix, i+1,j,maxi);

    if(matrix[i][j] == 1)
    {
        int side = 1+ min(right , min(diagonal,bottom));
        maxi = max(maxi,side);
        return side;
    }
    else
    {
        return 0;
    }

}

// rec + mem

int solveMem(vector<vector<int>> &matrix, int i, int j, int &maxi, vector<vector<int>>&dp)
{
    //base
    if(i>= matrix.size() || j>= matrix[0].size())
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int right = solve(matrix, i,j+1,maxi);
    int diagonal = solve(matrix, i+1,j+1,maxi);
    int bottom = solve(matrix, i+1,j,maxi);

    if(matrix[i][j] == 1)
    {
        int side = 1+ min(right , min(diagonal,bottom));
        maxi = max(maxi,side);
        return dp[i][j] =side;
    }
    else
    {
        return dp[i][j]= 0;
    }

}

// Tabulation
 
int solveTab(vector<vector<int>>&matrix,int n, int m, int &maxi)
{
    // create dp vector
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i = n-1; i>=0; i--)
    {
        for(int j = m-1; j>=0; j--)
        {
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int bottom = dp[i+1][j];

            if(matrix[i][j] == 1)
            {
                int side = 1+ min(right , min(diagonal,bottom));
                maxi = max(maxi,side);
                dp[i][j] = side;
            }
            else
            {
                dp[i][j]= 0;
            }
        }
    }

    return dp[0][0];
}
int main()
{
    int n = 4; int m =5;
    vector<vector<int>>matrix(n,vector<int>(m,0));
    matrix[0][0] = 1;
    matrix[1][0] = 1;
    matrix[2][0] = 1;
    matrix[3][0] = 1;
    matrix[2][1] = 1;
    matrix[0][2] = 1;
    matrix[1][2] = 1;
    matrix[2][2] = 1;
    matrix[1][3] = 1;
    matrix[2][3] = 1;
    matrix[1][4] = 1;
    matrix[2][4] = 1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }    

    // int maxi = 0;


    // solve(matrix,0,0, maxi);
    // cout<<"Ans is "<<maxi*maxi<<endl;

    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // int maxi = 0;
    // solveMem(matrix, 0,0,maxi,dp);

    // cout<<maxi*maxi<<endl;

    int maxi = INT_MIN;
    solveTab(matrix,n,m,maxi);
    cout<< " Ans using Tabulation  "<<maxi*maxi<<endl;
}