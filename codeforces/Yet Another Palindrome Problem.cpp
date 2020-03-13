#include<bits/stdc++.h>
using namespace std;

void solve()
{
   int n ;
   cin>>n;
   vector<vector<int>>loc(n+3);
   int val,i;
   for(i=0;i<n;i++)
   {
       cin>>val;
       loc[val].push_back(i);
   }
   
   for(i=0;i<loc.size();i++)
   {
       if(loc[i].size()>1 && loc[i].back()-loc[i][0]>=2)
       {
           cout<<"YES"<<endl;
           return;
       }
   }
    cout<<"NO"<<endl; 
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}