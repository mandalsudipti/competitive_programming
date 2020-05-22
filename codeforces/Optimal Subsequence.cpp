#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n+1,0);
    vector<int>sorted_arr(n+1,0);
    map<int,vector<int>>pos;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sorted_arr[i]=arr[i];
        pos[arr[i]].push_back(i);
    }
    sort(sorted_arr.begin(),sorted_arr.end(),greater<int>());
    int query;
    cin>>query;
    while(query--)
    {
        int len , k ;
        cin>>len>>k;
        vector<int>ans;
        int min_ele=sorted_arr[len-1] , freq=1;
        for(int i=len-2;i>=0;i--)
        {
            if(sorted_arr[i]==min_ele)
                freq++;
            else
                break;
        }
        for(auto itr=pos.begin();itr!=pos.end();++itr)
        {
            if(itr->first==min_ele)
            {
                vector<int>loc = itr->second ;
                for(int i=0;i<freq;i++)
                    ans.push_back(loc[i]);
            }
            else if(itr->first>min_ele)
            {
                vector<int>loc=itr->second;
                for(int i=0;i<loc.size();i++)
                    ans.push_back(loc[i]);
            }
        }
        sort(ans.begin(),ans.end());
        cout<<arr[ans[k-1]]<<endl;
    }
    return 0;
}

