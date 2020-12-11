#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        string S;
        cin>>S;
        string ans="";
        int cnt_t = 0 ;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='t')
                cnt_t++;
            else
                ans+=S[i];
        }
        
        for(int i=0;i<cnt_t;i++)
            ans+='t';
            
        cout<<ans<<endl;
    }
    
    return 0;
}