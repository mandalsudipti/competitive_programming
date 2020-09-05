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
        string S;
        cin>>S;
        string ans;
        int idx = 0 ;
        for(int i=0;i<n;i++)
        {
            ans+=S[i+idx];
            idx++;
        }
        
        cout<<ans<<endl;
    }
    return 0;
}