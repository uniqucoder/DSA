#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph
{
    public:

    map<T, list<pair<T,int > > > adjList;


    void addEdge(T u, T v, int weight, bool direction)
    {
        //for u->v
        adjList[u].push_back(make_pair(v,weight));

        //for v ->U
        if(direction == 0)
        {
            adjList[v].push_back(make_pair(u,weight));
        }

    }


    void printAdjList()
    {
        for(auto i : adjList)
        {
            cout<<i.first<<" -> ";

            for(auto j : i.second)
            {
                cout<<"("<<j.first<<","<<j.second<<") , ";

            }
            cout<<endl;
        }
    }

};


int main()
{

    Graph<int> g;

    g.addEdge(0, 1,3, 0);
    g.addEdge(1, 2,4, 0);
    g.addEdge(1, 3,9, 0);
    g.addEdge(2, 3,8, 0);
    g.addEdge(3, 4,11, 0);
    g.addEdge(2, 4,10, 0);

    g.printAdjList();
}