#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , m ;
        cin>>n;
        vector<int>red(n);
        for(int i = 0 ; i < n ; i++)
        {
            cin>>red[i];
            if(i > 0)
                red[i]+=red[i-1];
        }
        
        cin>>m;
        vector<int>blue(m);
        for(int i = 0 ; i < m ; i ++)
        {
            cin>>blue[i];
            if(i > 0)
                blue[i]+=blue[i-1];
        }
        
         int maximum = 0 , ans;
        for(int i = 0 ; i < n ; i++)
            maximum = max(maximum , red[i]);
            
        ans = maximum ;
        maximum = 0 ;
        for(int i = 0 ; i < m ;i++)
            maximum = max(maximum , blue[i]);
        ans+=maximum;
        
        cout<<ans<<endl;
    }
    
    return 0;
}