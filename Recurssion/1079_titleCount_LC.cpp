#include<bits/stdc++.h>
using namespace std;

void solve(string tiles,string&output, set<string>&result, /*map<int,bool>&vis*/ int vis[] )
{
    for(int i =0; i<tiles.length();i++)
    {   
        char ch = tiles[i];
            int index = ch -'A';
        
        if(vis[index] != 0 )
        {
            vis[index]--;
            output.push_back(tiles[i]);
            result.insert(output);
            solve(tiles,output,result, vis);
            // vis[i]=0;
            output.pop_back();
            vis[index]++;
        }
    }
}

int numTilePossibilities(string tiles)
{
    set<string>result;

    string output;
    // map<int,bool>vis; 
    
    int vis[26]={0};

    for(int i=0;i<tiles.length();i++)
    {
        char ch = tiles[i];
            int index = ch -'A';
            vis[index]++;
    }

    solve(tiles,output,result,vis);
    return result.size();




}

int main()
{
    string tiles="AAB";

    cout<<numTilePossibilities(tiles);

    return 0;
}