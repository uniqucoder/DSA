//Question Given and 2 d matrix , Count how many islands present
//iTs similar like no of disconnected commponents
// use dfs here

#include<bits/stdc++.h>
using namespace std;

void islands(int i, int j, vector<vector<int>> &grid)
{
    // base case
    if(i<0 || j < 0 || i >= grid.size() || j>= grid[i].size())
        return;
    
    if(grid[i][j] == 0)
        return;

    grid[i][j] = 0;    
    // 4 calls up down left right

    islands(i,j-1,grid);
    islands(i, j+1,grid);
    islands(i-1,j,grid);
    islands(i+1,j,grid);
}


int main()
{
    int n = 4, m = 5;
    vector<vector<int>> grid(n, vector<int>(m,0));

    grid[0][0] = 1;
    grid[0][1] = 1;
    grid[0][2] = 1;
    grid[0][3] = 1;
    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[1][3] = 1;
    grid[2][0] = 1;
    grid[2][1] = 1;

    for(auto i : grid)
    {
        for(auto j : i)
        {
            cout<<j<< " "; 
        }cout<<endl;
    }

    int count = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 1)
            {
                count++;
                islands(i,j,grid);
            }
        }
    }

    cout<<"No of Islands "<<count<<endl;
}