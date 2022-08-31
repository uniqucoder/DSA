#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph
{
    public:

    vector<vector<int> > edges;


    void addEdge(int u, int v, int wt)
    {
        vector<int>temp;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(wt);
        edges.push_back(temp);
    }

    void printEdges()
    {
        for(auto i : edges)
        {
            cout<<"(";
            for(auto j : i)
            {
                cout<<j<<",";
            }
            cout<<")";
            cout<<endl;
        }
    }

    void bellManFord(int src,int n, int m)
    {
        //initial step
        vector<int>dist(n+1,INT_MAX);

        dist[src] = 0;
        for(int i=1; i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if(dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // One more time for verification

        bool flag = false;
        for(int j =0;j<m;j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] + wt < dist[v])                {
                flag = true;
                break;
            }
        }
        if(flag == true)
        {
            cout<<"Negative cycle is present "<<endl;
        }
        else
        { 
            cout<<"Distance array is "<<endl;

            for(int i =1;i< dist.size();i++)
            {
                cout<<dist[i]<<" ";
            }
            cout<<endl;
        }

    }
};

int main()
{

    Graph<int>g;

    g.addEdge(1,2,2);
    g.addEdge(1,3,2);
    g.addEdge(2,3,-1);

    g.printEdges();
    g.bellManFord(1,3,3);

}