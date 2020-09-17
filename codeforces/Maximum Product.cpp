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
        int val;
        vector<long long int>positive;
        vector<long long int>negetive;
        
        for(int i=0;i<n;i++)
        {
            cin>>val;
            val>=0 ? positive.push_back(val) : negetive.push_back(val) ;
        }
        
        sort(positive.begin(),positive.end(),greater<long long int>());
        sort(negetive.begin(),negetive.end());
        
        long long int ans ;
        bool start = false ;
        if(positive.size()>=5)
        {
            ans = positive[0]*positive[1]*positive[2]*positive[3]*positive[4];
            start = true;
        }
        
        if(negetive.size()>=2 && positive.size()>=3)
        {
            long long int tmp = negetive[0] * negetive[1] * positive[0] * positive[1] * positive[2] ;
            if(!start)
            {
                ans = tmp ;
                start = true;
            }
            else
                ans = max(ans,tmp);
        }
        
        if(negetive.size()>=4 && positive.size()>=1)
        {
            long long int tmp = negetive[0]*negetive[1]*negetive[2]*negetive[3]*positive[0];
            if(!start)
            {
                ans = tmp ;
                start = true;
            }
            else
                ans = max(ans,tmp);
        }
        
        if(!start)
        {
            int x = 5 ;
            ans = 1 ;
            for(int i=negetive.size()-1;i>=0;i--)
            {
                if(x==0)
                    break;
                ans = ans*negetive[i];
                x--;
            }
        }
        
        if(n==5)
        {
            ans = 1 ;
            for(int i=0;i<positive.size();i++)
                ans = ans*positive[i];
            for(int i=0;i<negetive.size();i++)
                ans = ans*negetive[i];
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}


