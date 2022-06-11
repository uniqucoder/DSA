#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans,int n)
{
    vector<int>temp;

    for(int i=0;i<n;i++)
    {
        for(int j=0; j< n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}


bool isSafe(int row, int col,vector<vector<int>>&board ,  int n, map<int,bool>rowMap)
{
    // check for row
    int x = row;
    int y = col;
    cout<<"Iam in is safe"<<endl;
    cout<<row<<" "<<col<<endl;

    while(y >= 0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        y--;
    }

// Trying to optimis
    // if(rowMap[x]==1)
    // {
    //     return false;
    // } 

    // if(rowMap[x] == true)
    // {
    //     return false;
    // }

    cout<<"Printing Map"<<endl;

    for(auto &mp : rowMap)
    {
       cout<<"Map Elements are "<<mp.first<<" "<<mp.second<<"For row "<<x << "for col"<<y<<endl;
    }

    // check for diagonal

    
    x= row;
    y= col;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        y--;
        x--;
    }
    x= row;
    y= col;

    
    while(x < n && y>=0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }

    return true;
}

void solve(int col, int n, vector<vector<int>> &board, vector<vector<int>> &ans, map<int,bool>&rowMap)
{
    // base Casse
    if(col == n)
    {
        addSolution(board,ans,n);
        
        return;
    }

    // 1 casse solve rest recurssion will take care

    for(int row=0; row < n; row++)
    {

        rowMap.insert(make_pair(row,true));

        if(isSafe(row, col, board, n,rowMap))
        {
            board[row][col] = 1 ;
            solve(col+1,n,board,ans,rowMap);
            board[row][col] = 0 ;
        }
        rowMap.erase(row);
    }

    

}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>>board(n,vector<int>(n,0));

    vector<vector<int>> ans;

    map<int,bool>rowMap;

    solve(0,n,board,ans,rowMap);

    return ans;
}

int main()
{
  int n=2;

  vector<vector<int>>ans;
  ans=nQueen(n);

  for(int i=0; i< ans.size();i++)
  {
      for(int j=0; j <ans[i].size();j++)
      {
          cout<<ans[i][j]<<" ";
      }
      cout<<endl;

  }

  
  
}