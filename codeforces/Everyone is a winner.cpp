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
        set<int>ans;
        for(int i=1;i<=sqrt(n);i++)
        {
            ans.insert(i);
            ans.insert(n/i);
        }
        ans.insert(0);
        cout<<ans.size()<<endl;
        for(auto itr=ans.begin();itr!=ans.end();++itr)
        {
            cout<<(*itr)<<" ";
        }
        
        cout<<endl;
    }
    return 0;
}