#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n] , sum=0 , zero=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            if(arr[i]==0)
                zero++;
        }
        if(sum+zero==0)
            cout<<zero+1<<endl;
        else
            cout<<zero<<endl;
    }
    return 0;
}