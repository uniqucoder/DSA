// Toplogical sort 

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    public:
    map<T,list<T>>adjList;

    void addEdge(int u, int v,bool direction)
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
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

    void topoSort()
    {

        //step1 : find out all indegree
        map<int,int>indegree;
        queue<int>q;

        //initilise map 

        for(auto i : adjList)
        {
            indegree[i.first] = 0;
        }
        for(auto i : adjList)
        {
            for(auto j : i.second)
            {
                indegree[j]++;
            }
        }
        //step 2: push all elements whose indegree is 0
        for(auto i: indegree)
        {
            if(i.second == 0)
            {
                q.push(i.first);
            }
        }

        //step3 

        while(!q.empty())
        {
            int front = q.front();
            cout<<front<<" ";
            q.pop();

            for(auto neigh : adjList[front])
            {
                indegree[neigh]--;
                if(indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        cout<<endl;


    }

};
int main()
{
    Graph<int>g;

    g.addEdge(1,2,1);
    g.addEdge(1,3,1);
    g.addEdge(2,5,1);
    g.addEdge(3,5,1);
    g.addEdge(5,4,1);

    g.printAdjList();

    g.topoSort();
    
}