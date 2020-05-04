#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , query ;
    cin>>n>>query;
    vector<long long int>arr(n+1,0);
    vector<long long int>full_rot;
    vector<long long int>local_max(n+1,0);
    long long int maximum =0 ;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        local_max[i]=max(arr[i],local_max[i-1]);
    }
    maximum = max(arr[1],arr[2]);
    full_rot.push_back(min(arr[1],arr[2]));
    for(int i=3;i<=n;i++)
    {
        full_rot.push_back(min(maximum,arr[i]));
        maximum = max(maximum,arr[i]);
    }
    full_rot.insert(full_rot.begin(),maximum);
    
    while(query--)
    {
        long long int op ;
        cin>>op;
        if(op==1)
            cout<<arr[1]<<" "<<arr[2]<<"\n";
        else if(op<=n-1)
            cout<<local_max[op]<<" "<<arr[op+1]<<"\n";
        else
        {
            int x = op%(n-1) ;
            if(x==0)
                cout<<full_rot[0]<<" "<<full_rot.back()<<"\n";
            else
                cout<<full_rot[0]<<" "<<full_rot[x]<<"\n";
        }
    }
    
    return 0;
}
