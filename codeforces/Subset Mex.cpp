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
        map<int,int>freq;
        int val;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            freq[val]++;
        }
        
        int ans = -1 ;
        for(int i=0;i<105;i++)
        {
            if(freq[i]==1 && ans==-1)
                ans = i;
            if(freq[i]==0)
            {
                if(ans==-1)
                    ans = 2*i;
                else
                    ans+=i;
                break;
            }
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}