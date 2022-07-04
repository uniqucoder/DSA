#include<bits/stdc++.h>
using namespace std;


bool knows(int a, int b, int arr[4][4])
{
    return arr[a][b];
}

int findCelebrity(int arr[4][4], int n) {

    //Push All Elements all to stack
    stack<int>s;

    for(int i=0;i<n;i++)
    {
        s.push(i);
    }

    //find candiate may celebrity
    while(s.size() > 1)
    {
        // first ele
        int first = s.top();
        s.pop();
        //second ele
        int second = s.top();
        s.pop();


        if(knows(first,second,arr))
        {
            s.push(second);
        }
        else
        {
            s.push(first);
        }
    }

    int candidate = s.top();
    s.pop();


    // check for row 
    bool checkRow = true;
    for(int i=0; i< n;i++)
    {
        if(arr[candidate][i] == 1)
        {
            checkRow = false;
            break;
        }
    }


    //check col
    bool checkCol = true;

    for(int i=0;i<n;i++)
    {
        if(i!=candidate && arr[i][candidate] == 0)
        {
            checkCol = false;
            break;
        }
    }

    if(checkCol & checkRow)
    {
        return candidate;
    }
    return -1;
}

int main()
{
    int arr[4][4]={{0,0,1,0},{0,0,1,0},{0,0,0,0},{0,0,1,0}};
    
    cout<<"Celebrity is "<<findCelebrity(arr,4)<<endl;
    
    
}