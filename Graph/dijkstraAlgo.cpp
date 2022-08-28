#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{

    public:

    map<int,list<pair<int,int> > > adjList;

    void addEdge(int u, int v, int wt, bool direction)
    { 
        adjList[u].push_back({v,wt});

        if(direction == 0)
        {
            adjList[v].push_back(make_pair(u,wt));
        }
    }

    void printAdjList()
    {
        for(auto i : adjList)
        {
            cout<<i.first<< " => ";

            for(auto j : i.second)
            {
                cout<<"("<<j.first<<","<<j.second<<") , ";
            }cout<<endl;

        }
    }

    vector<int> dijkstra(int src,int n)
    {
        //Initial step : Create dist array
        vector<int>dist(n+1,INT_MAX);
        set<pair<int,int>> st;

        //update dist of src = 0 and push into the set

        dist[src] = 0;
        st.insert(make_pair(0,src));

        // same like bfs
        while(!st.empty())
        {
            auto top = *(st.begin());
            //remove from set
            st.erase(st.begin());

            int nodeDistance = top.first;
            int node = top.second;

            //step2 : check nei

            for(auto nei : adjList[node])
            {
                // dist updation
                if(nodeDistance + nei.second < dist[nei.first])
                {
                    // remove old record;

                    auto record = st.find(make_pair(dist[nei.first],nei.first));

                    if(record != st.end())
                    {
                        st.erase(record);
                    }
                    //new distace
                    dist[nei.first] = nodeDistance + nei.second;

                    //push to set
                    st.insert(make_pair(dist[nei.first],nei.first));
                }

            }

        }
        return dist;
    }

    vector<int> solve(int src, int n)
    {
        //initial step
        vector<int>dist(n+1, INT_MAX);


        set<pair<int,int> > st;

        dist[src] = 0;
        st.insert(make_pair(0,src));

        //step1
        while(!st.empty())
        {
            auto top = *(st.begin());

            st.erase(st.begin());

            int distanceNode = top.first;
            int node = top.second;

            for(auto nei : adjList[node])
            {
                if(distanceNode + nei.second < dist[nei.first] )
                {

                    auto record = st.find(make_pair(dist[nei.first],nei.first));
                    
                    if(record != st.end())
                    {
                        st.erase(record);
                    }

                    dist[nei.first] = distanceNode + nei.second;

                    st.insert(make_pair(dist[nei.first],nei.first));
                }
            }

        }

        return dist;

        
    }

};





int main()
{
    Graph<int>g;
    // g.addEdge(0,1,5,0);
    // g.addEdge(0,2,8,0);
    // g.addEdge(1,2,9,0);
    // g.addEdge(3,1,2,0);
    // g.addEdge(3,2,6,0);

    g.addEdge(0,1,2,0);
    g.addEdge(0,2,3,0);
    g.addEdge(0,3,6,0);
    g.addEdge(1,3,3,0);
    g.addEdge(2,3,2,0);
    g.addEdge(3,4,4,0);
    g.addEdge(3,5,2,0);
    g.addEdge(4,5,4,0);






    cout<<"Printinf AdjList"<<endl;
    g.printAdjList();
    cout<<endl;


    vector<int> dist = g.solve(0,5);

    for(auto i : dist)
    {
        cout<<i<<" ";
    }cout<<endl;
}