#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph
{
    public:

    map<int, list <pair<T,T> > > adjList;

    void addEdge(int u, int v,int weight, bool direction)
    {
        adjList[u].push_back(make_pair(v,weight));

        if(direction == 0)
        {
            adjList[v].push_back(make_pair(u,weight));
        }
    }



    void printAdjList()
    {
        for(auto i : adjList)
        {
            cout<<i.first<<" => ";

            for(auto j : i.second)
            {   cout<<"(";
                cout<<j.first<<" , "<<j.second;
                cout<<")"; 
            }
            cout<<endl;
        }
        cout<<endl;
    }

};


int main()
{

    Graph<int>g;

    g.addEdge(1,2,3,1);
    g.addEdge(2,3,4,1);
    g.addEdge(2,4,5,1);
    g.addEdge(4,3,6,1);



    g.printAdjList();
}