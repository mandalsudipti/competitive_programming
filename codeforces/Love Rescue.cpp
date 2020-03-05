#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,i;
        cin>>n;
        long long int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        long long int max_local=0 , max_global=0;
        for(i=0;i<n;i++)
        {
            max_local = max(0ll,max_local+arr[i]);
            max_global= max(max_global,max_local);
        }
        if(max_global>0)
            cout<<max_global<<endl;
        else
        {
            max_global=arr[0];
            for(i=1;i<n;i++)
            {
                if(arr[i]>max_global)
                    max_global=arr[i];
            }
            cout<<max_global<<endl;
        }
    }
    return 0;
}