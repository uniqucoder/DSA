//adjustancy list
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



    void BFS(int src, map<int,bool> &visited)
    {
        queue<int>q;
        
        q.push(src);
        visited[src] = true;

        while(!q.empty())
        {
            int front = q.front();
            cout<<front<<" ";
            q.pop();

            for(auto neibours : adjList[front])
            {
                if(!visited[neibours])
                {
                    q.push(neibours);
                    visited[neibours] = true;

                }
            }
        }
  
    }

    void DFS(int src, map<int,bool> &visited)
    {
        visited[src] = true;
        cout<<src<<", ";

        for(auto neighbour : adjList[src])
        {
            if(!visited[neighbour])
            {
                visited[neighbour] = true;
                DFS(neighbour,visited);
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
   
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(2,4,0);

    cout<<"Printing Adjecency List"<<endl;

    g.printAdjList();

    cout<<endl;
    map<int,bool> visited;
    cout<<"Printing BFS Traversal"<<endl;
    int n = 5;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            g.BFS(i,visited);
        }
    }
    cout<<endl;
    cout<<"Printing the DFS Traversal"<<endl;

    Graph<int>g2;
    map<int,bool> visited2;
    g2.addEdge(0,2,0);
    g2.addEdge(2,3,0);
    g2.addEdge(2,4,0);
    g2.addEdge(3,2,0);
    g2.addEdge(3,4,0);
    g2.addEdge(3,1,0);


    for(int i=0;i<n;i++)
    {
        if(!visited2[i])
            g2.DFS(0,visited2);
    }
}