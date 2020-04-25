#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n , k , val;
    cin>>n>>k;
    set<int>freq;
    queue<int>arr;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        if(!freq.count(val))
        {
            arr.push(val);
            freq.insert(val);
            if(arr.size()>k)
            {
                int x = arr.front();
                freq.erase(x);
                arr.pop();
            }
        }
    }
    vector<int>ans;
    while(!arr.empty())
    {
        ans.push_back(arr.front());
        arr.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
        
    return 0;
}