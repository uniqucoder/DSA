/*

    Step 1: Find Topological sort using dfs (This not valid because it contains Cycle we can only find the topological sort
        of DIRECECt Acyclic Graph)

    Step 2: Traspose of Graph  (U -> V)  do ( V -> U) , It will give us Strongly connected comonents

    Step3 : Travsere DFS accoording to toposort stored in Stack ,and count DONE!!!

*/

#include<bits/stdc++.h>
using namespace std;

template<typename T >
class Graph
{
    public:

    map<T, list<T> > adjList;


    void addEdge(int u, int v , bool direction){
        adjList[u].push_back(v);
        if(direction == 0)
            adjList[v].push_back(u);
    }

    void printAdjList()
    {
        
        for(auto i : adjList)
        {
            cout<<i.first<<"=> ";
            for(auto j : i.second)
                cout<<j<<" ,";
            cout<<endl;
        }
    }

    void dfs(int src, stack<int>&st , map<int,bool>&vis)
    {
        vis[src] = true;

        for(auto nei : adjList[src])
        {
            if(!vis[nei])
            {
                vis[nei] = true;
                dfs(nei,st,vis);
            }
        }
        st.push(src);
    }

    //step2 :Transpose of adjlist
    void transpose(map<int,list<int>> &newAdjList)
    {
        for(auto i : adjList)
        {
            for(auto j : i.second)
            {
                newAdjList[j].push_back(i.first);
            }
        }
    }

    void revdfs(int src, map<int,bool>&vis, map<int, list<int> > &newadjList)
    {
        cout<<src<<", ";
        vis[src] = true;
        for(auto nei : newadjList[src])
        {
            if(!vis[nei])
            {
                vis[nei] = true;
                revdfs(nei,vis,newadjList);
            }
        }
    }
};

int main()
{


    Graph<int>g;
    g.addEdge(1,2,1);
    g.addEdge(2,0,1);
    g.addEdge(0,1,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);

    g.printAdjList();

    cout<<endl;

    
    //step1 :

    stack<int>st;
    int n = 5;
    map<int,bool>vis;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
           g.dfs(i,st,vis);
        }
    }


    //step2: Tranpose of adjlist
    map<int,list<int> > newAdjList;
    g.transpose(newAdjList);

    //step3 According toposort
    map<int,bool> vis2;
    int count=0;
    
    while(!st.empty())
    {
        if(!vis2[st.top()])
        {
            count++;
            g.revdfs(st.top(),vis2,newAdjList);
        }
        st.pop();
    }
    
    cout<<"\n No SCC are " <<count<<"";

    return 0;    
}