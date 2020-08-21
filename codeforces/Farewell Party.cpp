#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    map<int,vector<int>>same_hat;
    vector<int>arr(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        same_hat[n-arr[i]].push_back(i);
    }
    
    vector<int>ans(n);
    int hat = 1 ;
    
    for(auto itr=same_hat.begin();itr!=same_hat.end();++itr)
    {
       vector<int>tmp = itr->second ;
       if( (tmp.size()< itr->first) || (tmp.size()%itr->first)!=0 )
       {
           cout<<"Impossible";
           return 0;
       }
       
       for(int i=0;i<tmp.size();i+=itr->first)
       {
           for(int j=i;j<i+itr->first;j++)
                ans[tmp[j]] = hat ;
            hat++;
       }
    }
    
    cout<<"Possible"<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
        
    return 0;
}