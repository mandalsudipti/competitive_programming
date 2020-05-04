#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , k;
        cin>>n>>k;
        set<int>distinct;
        int arr[n];
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            distinct.insert(arr[i]);
        }
        if(distinct.size()>k)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            int start = 0 , idx = 0 , i ;
            set<int>distinct_k ;
            for(int i=0;i<k;i++)
                distinct_k.insert(arr[i]);
            if(distinct_k.size()==distinct.size())
            {
                start=k;
                for(int i=0;i<k;i++)
                    ans.push_back(arr[i]);
            }
            else
            {
                
                for(i=0;i<k;i++)
                {
                    if(distinct.size()==0)
                    {
                        ans.push_back(arr[start++]);
                    }
                    else 
                    {
                        if(distinct.find(arr[start])!=distinct.end())
                        {
                            ans.push_back(arr[start]);
                            distinct.erase(distinct.find(arr[start]));
                            start++;
                        }
                        else
                        {
                            auto val = distinct.begin();
                            ans.push_back(*val);
                            distinct.erase(distinct.begin());
                        }
                    }
                }
            }
            i=start;
            while(i<n)
            {
                ans.push_back(ans[idx]);
                if(ans[idx]==arr[i])
                {
                    i++;
                }
                idx++;
            }
            
            cout<<ans.size()<<endl;
            for(i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}