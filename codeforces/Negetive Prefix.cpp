#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>arr(n);
        vector<int>state(n);
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<n;i++)
            cin>>state[i];
        
        vector<int>tmp;
        for(int i=0;i<n;i++)
        {
            if(state[i]==0)
                tmp.push_back(arr[i]);
        }
        
        sort(tmp.begin(),tmp.end(),greater<int>());
        int idx = 0 ;
        for(int i=0;i<n;i++)
        {
            if(state[i]==1)
                cout<<arr[i]<<" ";
            else
            {
                cout<<tmp[idx]<<" ";
                idx++;
            }
        }
        cout<<endl;
    }
    
    return 0;
}