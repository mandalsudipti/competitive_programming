#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n] , cnt=0;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=1;i<n-1;i++)
    {
        if(arr[i-1]==1 && arr[i+1]==1 && arr[i]==0)
        {
            arr[i+1]=0;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}