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

    Info(int d, int c, int r)
    {
        this->data = d;
        this->col = c;
        this->row = r;
    }
};

class Cmp
{

    public:

    bool operator()(Info* a, Info* b)
    {
        return a->data > b ->data;
    }


};


int solve(vector<vector<int>>arr, int k, int n)
{
    int mini = INT_MAX;

    int maxi = INT_MIN;

    // create priority queue
    priority_queue<Info*, vector<Info*> , Cmp > minHeap;

    // process first k element


    
    for(int i =0;i< k;i++)
    {
        int element = arr[i][0];

        mini = min(mini, element);
        maxi = max(maxi,element);

        Info* temp = new Info(element,i,0);

        minHeap.push(temp);
    }

    int start = mini;
    int end = maxi;

    while (!minHeap.empty())
    {
        Info* temp = minHeap.top();
        minHeap.pop();

        //save data into mini
        mini = temp->data;

        // update the ans

        if(end - start > maxi - mini)
        {
            start = mini;
            end = maxi;
        }

        // add next element to the minheap

        if(temp->col +1 < arr[temp->row].size())
        {
            Info* toPush = new Info(arr[temp->row][temp->col+1], temp->row , temp->col+1);
            maxi = max(toPush->data, maxi);

            minHeap.push(toPush);
        }
        else
        {
            // if this happen means on of the list completly traversed so we 
            //break bcoz base condn is at least one element should present the range
            break;
        }
    }

    cout<<" Start "<<start << "  End   "<<end<<endl;
    return end - start;
    
}

int main()
{

    int n = 4;
    vector<vector<int>>arr(n,vector<int>(n,0));


    arr[0][0]=4;
    arr[0][1]=10;
    arr[0][2]=15;
    arr[0][3]=24;
    
    arr[1][0]=0;
    arr[1][1]=9;
    arr[1][2]=12;
    arr[1][3]=20;
    
    arr[2][0]=5;
    arr[2][1]=18;
    arr[2][2]=22;
    arr[2][3]=30;



    cout<<solve(arr, 3, 4)<<endl;
    


    return 0;



}