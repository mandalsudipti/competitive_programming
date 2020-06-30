#include<bits/stdc++.h>
using namespace std;

const int available = 0 , used = 1 , blocked = -1;

int main()
{
    int n ;
    cin>>n;
    vector<int>arr(n);
    vector<int>B(n,-1);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int>fill_up(arr[n-1]+10,available);
    for(int i=0;i<n;i++)
        fill_up[arr[i]]=blocked;
        
    int idx = 0;
    for(int i=0;i<n;i++)
    {
        int used_num = -1;
        for(int j=idx;j<fill_up.size();j++)
        {
            if(fill_up[j]==available)
            {
                B[i]=j;
                fill_up[j]=used;
                idx=j;
                break;
            }
            if(fill_up[j]==used)
                used_num = j;
        }
        if(B[i]==-1)
        {
            B[i]=used_num;
            idx = used_num;
        }
        if(i+1<n && arr[i+1]>arr[i])
        {
            fill_up[arr[i]]= available;
            idx = arr[i];
            //cout<<B[i]<<endl;
        }
    }
    for(int i=0;i<arr[n-1];i++)
    {
        if(fill_up[i]!=used)
        {
            cout<<"-1";
            return 0;
        }
    }
    for(int i=0;i<n;i++)
        cout<<B[i]<<" ";
    return 0;
}

