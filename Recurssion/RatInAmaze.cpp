#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y , int n, vector<vector<int>> &arr, vector<vector<int>>&vis)
    {
        
        if((x >= 0 && x < n)&&(y >= 0 && y < n)&&(arr[x][y] == 1 )&&(vis[x][y] == 0))
        {
            return true;
        }
        return false;
    }
    void solve(int x, int y, vector<vector<int>>&arr, int n, vector<string>&ans,vector<vector<int>>&vis,string path )
    {
        // base case
        if(x==n-1 && y==n-1)
        {
            ans.push_back(path);
            
            return;
        }

        string d="DLRU";
        int dx[]={+1,0,0,-1};
        int dy[]={+0,-1,1,0};
        
        for(int i=0;i<d.length();i++)
        {
            int nextX = x+dx[i];
            int nextY = y+dy[i];
            
            if(isSafe(nextX, nextY, n,arr,vis))
            {
                vis[x][y]=1;
                path.push_back(d[i]);
                solve(nextX, nextY,arr,n,ans,vis,path);
                path.pop_back();
                vis[x][y]=0;
            }
            
        }
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &arr, int n) {
        // Your code goes here
        vector<string>ans;
        
        if(arr[0][0]==0)
        {
            return ans;
            
        }
        
        string path="";
        
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        solve(0,0,arr,n,ans,vis,path);
        
        return ans;
       
    }


int main()
{
    int n =4;
    vector<vector<int>> arr(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0; j< n;j++)
        {
            cin>>arr[i][j];
        }
    }

    vector<string>ans;

    ans = findPath(arr,n);

    if(ans.size() == 0)
    {
        cout<<"-1"<<endl;
    }

    for(int i=0;i<ans.size();i++)
    {
        for(int j = 0; j< ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;

    }
}