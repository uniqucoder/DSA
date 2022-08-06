//with out weight

#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph
{
    public:

    map<T, list<T> > adjList;

    void addEdge(T u, T v, bool direction)
    {
        //u -> v 1 edge always there 

        adjList[u].push_back(v);

        // if it is undirected for v -> u
        if(direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(auto i :adjList)
        {
            cout<<i.first<< " -> ";

            for(auto j : i.second)
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

    void BFS(int src)
    {
        queue<int>q;
        q.push(src);

        map<int,bool> visited;
    

        while (!q.empty())
        {
            int front = q.top();
            cout<<front<<", ";
            q.pop();
            for(auto neigbours : adjList[front])
            {
                if(!visited[neigbours])
                {
                    q.push(neigbours);
                    visited[neigbours] = true;
                }
            }
        }
    }

};

int main()
{

    //generic

    Graph<int> g;

    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(2,4,0);

    cout<<"Printing Adjecency List"<<endl;

    g.printAdjList();

    cout<<endl;
    cout<<"Printing BFS Traversal"<<endl;
    g.BFS(0);
}