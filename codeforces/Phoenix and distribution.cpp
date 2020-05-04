#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , k;
        cin>>n>>k;
        string S;
        cin>>S;
        sort(S.begin(),S.end());
        if(S[0]!=S[k-1])
        {
            cout<<S[k-1]<<endl;
        }
        else
        {
            string ans ;
            ans+=S[k-1];
            bool all_same = true ;
            for(int i=k+1;i<n;i++)
            {
                if(S[i]!=S[k])
                {
                    all_same=false;
                    break;
                }
            }
            if(all_same)
            {
                int len = (n - k)/k + ((n-k)%k!=0) ;
                for(int i=0;i<len;i++)
                    ans+=S[k];
            }
            else
            {
                for(int i=k;i<n;i++)
                    ans+=S[i];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
