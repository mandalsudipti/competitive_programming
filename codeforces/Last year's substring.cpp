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
        
        if(S[0]=='2' && S[1] == '0' && S[2] =='2' && S[3] == '0')
            cout<<"YES"<<endl;
        else if(S[0]=='2' && S[1] == '0' && S[2] =='2' && S[n-1] == '0')
            cout<<"YES"<<endl;
        else if(S[0]=='2' && S[1] == '0' && S[n-2] =='2' && S[n-1] == '0')
            cout<<"YES"<<endl;
        else if(S[0]=='2' && S[n-3] == '0' && S[n-2] =='2' && S[n-1] == '0')
            cout<<"YES"<<endl;
        else if(S[n-4]=='2' && S[n-3] == '0' && S[n-2] =='2' && S[n-1] == '0')
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}