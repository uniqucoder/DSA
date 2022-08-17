#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    public:

    map<int,list<T>> adjList;

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
            cout<<i.first<<" -> ";

            for(auto j : i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    bool isCyclicDfsDirected(int src, map<int,bool>&visited, map<int,bool>&dfsVisited )
    {
        //step 1:
        visited[src] = true;
        dfsVisited[src] = true;

        for(auto neighbour : adjList[src])
        {
            if(!visited[neighbour])
            {
                bool cycleDetected = isCyclicDfsDirected(neighbour,visited,dfsVisited);

                if(cycleDetected == true)
                    return true;
            }
            else if( visited[neighbour] == true && dfsVisited[neighbour] == true)
            {
                return true;
            }
        }
        dfsVisited[src] = false;

        return false;
    } 


};

int main()
{
    Graph<int>g;
    g.addEdge(1,2,1);
    g.addEdge(2,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,4,1);
    g.addEdge(2,3,1);
    g.addEdge(3,7,1);
    g.addEdge(3,8,1);
    g.addEdge(8,7,1);
    cout<<endl;
    cout<<"Printing ADJLISt => "<<endl;
    g.printAdjList();
    cout<<endl;

    map<int,bool>visited;
    map<int,bool>dfsvisited;
    cout<<"Cycle present in DFS "<<g.isCyclicDfsDirected(1,visited,dfsvisited)<<endl;
}