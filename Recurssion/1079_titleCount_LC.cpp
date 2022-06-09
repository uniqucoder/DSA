#include<bits/stdc++.h>
using namespace std;

void solve(string tiles,string&output, set<string>&result,map<int,bool>&vis )
{
    for(int i =0; i<tiles.length();i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            char ch = tiles[i];
            output.push_back(ch);
            result.insert(output);
            solve(tiles,output,result, vis);
            vis[i]=0;
            output.pop_back();
        }
    }
}

int numTilePossibilities(string tiles)
{
    set<string>result;

    string output;
    map<int,bool>vis;
    solve(tiles,output,result,vis);
    return result.size();




}

int main()
{
    string tiles="AAABBC";

    cout<<numTilePossibilities(tiles);

    return 0;
}