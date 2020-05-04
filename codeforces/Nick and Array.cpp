#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<int>arr;
    int val;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        if(val>=0)
            arr.push_back(val*(-1) -1);
        else
            arr.push_back(val);
    }
    if(n%2==1)
    {
        int minimum = 0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]<arr[minimum])
                minimum=i;
        }
        arr[minimum] = arr[minimum]*(-1) - 1;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        
    return 0;
}