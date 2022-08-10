#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    int** adjMat;
    int v;

    Graph( int v)
    {
        this -> v = v;

        adjMat = new int*[v];
        for(int i=0;i< v;i++)
        {
            adjMat[i] = new int[v];

            for(int j=0; j< v; j++)
            {
                adjMat[i][j] = 0;
            }
        }

    }


    void addEdge(int u, int v, bool direction)
    {
        adjMat[u][v] = 1;

        if(direction == 0)
        {
            adjMat[v][u] = 1;
        }
    }


    void removeEdge(int u, int v)
    {
        adjMat[u][v] = 0;
        adjMat[v][u] = 0;
    }

    void printAdjMat()
    {
        for(int i=0;i < v; i++)
        {
            for(int j =0; j< v; j++)
            {
                cout<<adjMat[i][j]<<" ";
            }
            cout<<endl;
        }
       
    }

    void BFS(int src, map<int,bool>&visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int front = q.front();
            cout<<front<<" ";
            q.pop();
            
            for(int j=0;j < v;j++)
            {   
                if(adjMat[front][j] == 1 && !visited[j])
                {
                    visited[j] = true;
                    q.push(j);
                }
            }

        }
        
    }

    void DFS(int src, map<int,bool> &visited2)
    {
        visited2[src] = true;
        cout<<src<<" ";

        for(int j = 0;j<=v; j++)
        {
            if(!visited2[j] && adjMat[src][j] == 1)
            {
                visited2[j] = true;
                DFS(j, visited2);
            }
        }
        
    }

};


int main()
{
    int v = 6;
    Graph g(v);

    for(int i=0;i< v;i++)
    {
        for(int j=0;j< v;j++)
        {
            cout<<g.adjMat[i][j]<<" ";
        }
        cout<<endl;
    }

    g.addEdge(0,1,0);
    g.addEdge(0,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,3,0);
    g.addEdge(2,4,0);
    g.addEdge(2,5,0);


    g.addEdge(3,4,0);
    g.addEdge(4,5,0);


    cout<<"Printing adjcency Matrix"<<endl;
    g.printAdjMat();

    cout<<"Printing BFS Traversal "<<endl;

    map<int,bool> visited;

    for(int i=0;i< v;i++)
    {
        if(!visited[i])
        {
            g.BFS(0,visited);
        }
    }
    cout<<endl;

    cout<<"printing the DFS "<<endl;

    map<int,bool> visited2;

    for(int i=0; i< v;i++)
    {
        if(!visited2[i])
        {
            g.DFS(0,visited2);
        }
    }
    

}