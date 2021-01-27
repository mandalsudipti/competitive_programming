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
        int cnt  = 0 ;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            if(S[i] == ')')
                cnt++;
            else
                break;
        }
        
        if(cnt > n - cnt)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    
    return 0 ;
}
