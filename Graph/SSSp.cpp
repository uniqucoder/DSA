// Shortest path using BFS Algorithm

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    public:
    map<T,list<T> > adjList;

    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);

        if(direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(auto i : adjList)
        {
            cout<<i.first<<" => ";

            for(auto j : i.second)
            {
                cout<<j<<" ,";
            }cout<<endl;
        }
    }
    
    vector<int> getShortestPath(int src, int dest, map<int,bool> &visited)
    {
        vector<int>ans;
        queue<int>q;
        map<int,int> parent;

        //step 1: push source node to queue and update visited and parent datastructure for the same

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto neigh : adjList[front])
            {
                if(!visited[neigh])
                {
                    visited[neigh] = true;
                    parent[neigh] = front;
                    q.push(neigh);
                }
            }
        }


        // for(auto i : parent)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }

        ans.push_back(dest);

        while (parent[dest] != src)
        {
            ans.push_back(parent[dest]);
            dest = parent[dest];
        }
        ans.push_back(src);
        
        reverse(ans.begin(),ans.end());

        return ans;
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(1,4,0);
    g.addEdge(2,5,0);
    g.addEdge(5,8,0);
    g.addEdge(3,8,0);
    g.addEdge(4,6,0);
    g.addEdge(6,7,0);
    g.addEdge(7,8,0);
    

    g.printAdjList();


    vector<int>ans;

    int src = 1, dest = 8;
    map<int,bool> visited;

    ans = g.getShortestPath(src,dest, visited);

    for(auto i: ans)
    {
        cout<<i<<" => ";
    }
    cout<<endl;


}