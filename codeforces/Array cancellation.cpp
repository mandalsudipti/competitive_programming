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
        vector<long long int>val(n);
        vector<long long int>positive;
        vector<long long int>negetive;
        
        for(int i=0;i<n;i++)
        {
            cin>>val[i];
            val[i]<0 ? negetive.push_back(i) : positive.push_back(i);
        }
        int  n_idx = 0 ;
        for(int i=0;i<positive.size();i++)
        {
            while(val[positive[i]]>0 && n_idx<negetive.size())
            {
                while(n_idx<negetive.size() && (negetive[n_idx]<positive[i]||val[negetive[n_idx]]==0))
                    n_idx++;
                if(n_idx==negetive.size())
                    break;
                //cout<<val[positive[i]]<<" "<<val[negetive[n_idx]]<<endl;
                long long int x = min(val[positive[i]],abs(val[negetive[n_idx]]));
                val[positive[i]]-=x;
                val[negetive[n_idx]]+=x;
            }
        }
        
        long long int ans = 0 ;
        for(int i=0;i<positive.size();i++)
            ans+=val[positive[i]];
            
        cout<<ans<<endl;
    }
    
    return 0;
}
