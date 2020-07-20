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
        set<int>distinct;
        vector<int>ans;
        int val , tmp ;
        for(int i=0;i<2*n;i++)
        {
            cin>>val ;
            tmp = distinct.size();
            distinct.insert(val);
            if(tmp<distinct.size())
                ans.push_back(val);
        }
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}