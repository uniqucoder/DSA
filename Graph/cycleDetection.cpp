#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    public:

    map<int,list<T> > adjList;


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
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

    bool isCyclicBFS(int src)
    {
        map<int,bool> visited;
        map<int,int> parent;

        queue<int>q;

        //first step
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto neighbour : adjList[front])
            {
                if(visited[neighbour] == true && neighbour != parent[front])
                {
                    return true;
                }
                else if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                }
            }
        }

        return false;
    }

    bool isCyclicDFS(int src, int parent, map<int,bool>&visited)
    {
        //step 1 :-> mark visited as true

        visited[src] = true;

        //check neighbours
        for(auto neighbour : adjList[src])
        {
            if(!visited[neighbour])
            {
                
                bool cycleDetected = isCyclicDFS(neighbour,src,visited);
                if(cycleDetected == true)
                    return true; 
            }
            else if( visited[neighbour] == true && neighbour != parent)
            {
                return true;
            }
        }

        return false;
    }

};



int main()
{
    Graph<int> g;

    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(3,5,0);
    g.addEdge(4,6,0);
    g.addEdge(5,6,0);
    g.addEdge(6,7,0);

    
    g.printAdjList();

    map<int,bool> visited;
    cout<<"Cycle Detection using DFS "<<g.isCyclicDFS(1,-1,visited);

}