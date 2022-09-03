#include<bits/stdc++.h>
using namespace std;

int roottenOranges(vector<vector<int>> &grid)
{
    //step1:
    int m = grid.size();
    int n = grid[0].size();

    //cout all fresh oranges and push rotten Organges into queue

    int fresh =0 ;

    queue<pair<int,int>> q;
    for(int i=0; i<m;i++)
    {
        for(int j=0; j<n;j++){
            if(grid[i][j] == 1)
                fresh++;
            
            if(grid[i][j] == 2)
            {
                q.push({i,j});
            }
        }
    }

    if(fresh == 0)
        return 0;
    
    int ans = 0;

    int x_row[] = {1,-1,0,0};
    int y_col[] = {0,0,1,-1};
    while(!q.empty() && fresh > 0)
    {
        int q_size = q.size();
        ans++;

        while(q_size--)
        {
            auto front = q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int x = front.first + x_row[i];
                int y = front.second + y_col[i];

                if(x>=0 && y>=0 && x <m && y <n && grid[x][y] == 1 )
                {
                    grid[x][y] = 2;
                    fresh--;
                    q.push({x,y});
                }
            }

        }

    }

    if(fresh > 0)
        return -1;
    return ans;


}
int main()
{
    vector<vector<int>> grid{{2,1,1},{1,1,0},{0,1,1}};


    cout<<roottenOranges(grid)<<endl;


}