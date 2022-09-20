#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int n, int target)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] ==  target)
            return i;
    }
    return -1;
}
int main()
{
    

    int arr[] = {1,2,3,6,4,5};
    int n = 6;
    int target = 6;
    int ans = search(arr, n, target);
    if(ans!=-1)
        cout<<"Element present at index "<<ans<<endl;

    else
        cout<<"Not present in an array"<<endl;

}