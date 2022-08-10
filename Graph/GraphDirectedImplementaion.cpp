#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    public:

    map<int,list<T> >adjList;


    void addEdge(int u, int v, bool directed)
    {
        adjList[u].push_back(v);

        if(directed == 0)
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
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }


    void BFS(int src, map<int,bool> &visited)
    {
        queue<int>q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int f = q.front();
            cout<<f<<" ";
            q.pop();

            for(auto neighbour : adjList[f] )
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        cout<<endl;
    }


    void DFSDirected(int src,map<int,bool>&visited)
    {
        cout<<src<<" ";
        visited[src] = true;

        for(auto neighbour : adjList[src])
        {
            if(!visited[neighbour])
            {
                visited[neighbour] = true;
                DFSDirected(neighbour,visited);
            }
        }
    }


};



int main()
{

    Graph<int>g;

    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(2,4,1);
    g.addEdge(4,3,1);


    cout<<"Printing the adjList"<<endl;

    g.printAdjList();

    map<int,bool> visited;
    for(int i=0; i<5;i++)
    {
        if(!visited[i])
        {
            g.DFSDirected(i,visited);
        }
    }
    cout<<endl;


    return 0;
}