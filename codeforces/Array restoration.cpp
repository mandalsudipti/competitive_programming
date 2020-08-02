#include<bits/stdc++.h>
using namespace std;

bool is_valid(vector<vector<int>>&range ,vector<bool>&visited , vector<int>&arr , int idx)
{
    int left = range[idx][0] , right = range[idx][1] ;
    if(left==-1)
        return true;
    for(int i=left;i<=right;i++)
    {
        if(arr[i]<idx && arr[i]!=0)
        {
            return false; 
        }
        if(arr[i]>idx)
        {
            visited[arr[i]] = true;
            int l = range[arr[i]][0] , r = range[arr[i]][1] ;
            if(l>=left && r<=right)
                continue;
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n , q ;
    cin>>n>>q;
    vector<int>arr(n);
    vector<bool>visited(q+1,false);
    vector<vector<int>>range(q+1,vector<int>(2,-1));
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(range[arr[i]][0]==-1)
            range[arr[i]][0] = range[arr[i]][1] = i ;
        else
            range[arr[i]][1] = i ;
    }
    
    for(int i=2;i<=q;i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            if(!is_valid(range,visited,arr,i))
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    if(range[q][0]==-1)
    {
        bool possible = false;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]==0)
            {
                arr[i]=q;
                possible = true;
                break;
            }
        }
        if(!possible)
        {
            cout<<"NO";
            return 0;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]!=0 && arr[i+1]==0)
            arr[i+1]=arr[i];
    }
    for(int i=n-1;i>0;i--)
    {
        if(arr[i]!=0 && arr[i-1]==0)
            arr[i-1]=arr[i];
    }
    for(int i=0;i<n;i++)
        if(arr[i]==0)
            arr[i]=q;
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        
    return 0;
}


