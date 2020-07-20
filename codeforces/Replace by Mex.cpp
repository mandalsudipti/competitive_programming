#include<bits/stdc++.h>
using namespace std;

int find_mex(vector<int>&freq, int mex)
{
    for(int i=mex+1;i<freq.size();i++)
    {
        if(freq[i]==0)
            return i;
    }
    return -1;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>arr(n);
        vector<int>freq(n,0);
        set<int>not_in_order;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]<n)  freq[arr[i]]++;
        }
        int mex = find_mex(freq,-1) ;
       
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            if(freq[arr[i]]>1 || arr[i]==n)
            {
                if(arr[i]<n)
                    freq[arr[i]]--;
                arr[i] = mex ;
                freq[mex]++;
                mex = find_mex(freq,mex);
                ans.push_back(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=i)
                not_in_order.insert(arr[i]);
        }
        
        mex = n ;
       while(true)
        {
            if(mex==n)
            {
                if(not_in_order.size()<=1)
                    break;
                int idx = *(not_in_order.begin());
                int t = mex ;
                mex = arr[idx];
                arr[idx]=t;
                ans.push_back(idx);
            }
            else
            {
                ans.push_back(mex);
                int t = arr[mex];
                arr[mex] = mex ;
                not_in_order.erase(not_in_order.find(mex));
                mex = t ;
            }
        }
        
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]+1<<" ";
        cout<<endl;
        /*for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;*/
    }
    return 0;
}

