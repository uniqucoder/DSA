#include<bits/stdc++.h>
using namespace std;

class Info
{
    public:

    int data;
    int row;
    int col;

    Info()
    {

    }
    Info(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this ->col = col;
    }
};

class Cmp
{
    public:

    bool operator()(Info* a, Info* b)
    {
        return a->data > b->data;
    }
};


vector<int> mergeKSortedArray(vector<vector<int> > &arr, int k)
{

    priority_queue<Info*,vector<Info*>,Cmp> minHeap;

    vector<int>ans;
    int n = arr[0].size();
    // Step 1: Copy k element to min heap
    for(int i=0;i<k;i++)
    {
        int element = arr[i][0];

        Info* temp= new Info(element,i,0);

        minHeap.push(temp);
    }

    while(minHeap.size() > 0)
    {
        Info* tmp = minHeap.top();
        minHeap.pop();
        ans.push_back(tmp->data);
        int col = tmp->col;
        int row = tmp->row;
        if(col+1 < n)
        {
            Info* temp = new Info(arr[row][col+1],row,col+1);
            minHeap.push(temp); 
        }
    }

    return ans;
}

int main()
{

    int n =4;
    vector<vector<int>> arr(3, vector<int> (4, 0));


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    arr[0][0] = 1;
    arr[0][1] = 3;
    arr[0][2] = 5;
    arr[0][3] = 7;

    arr[1][0] = 2;
    arr[1][1] = 4;
    arr[1][2] = 6;
    arr[1][3] = 8;

    arr[2][0] = 0;
    arr[2][1] = 9;
    arr[2][2] = 10;
    arr[2][3] = 11;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<int> ans = mergeKSortedArray(arr, 3);


    for(auto &i : ans)
    {
        cout<<i<<" ";
    }cout<<endl;





}