#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int p , q ;
        cin>>p>>q;
        if(p%q!=0)
            cout<<p<<endl;
        else
        {
            vector<long long int>factor;
            for(int i=2;i<=sqrt(q);i++)
            {
                if(q%i==0)
                {
                    factor.push_back(i);
                    factor.push_back(q/i);
                }
            }
            factor.push_back(q);
            sort(factor.begin(),factor.end());
            
            long long int ans = 1 ;
            for(int i=0;i<factor.size();i++)
            {
                long long int x = factor[i] ;
                while((p/x)%q==0)
                    x = factor[i]*x ;
                if(x<p)
                    ans = max(ans,(p/x));
            }
            
            cout<<ans<<endl;
        }
    }
    
    return 0;
}

