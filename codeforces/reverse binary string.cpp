#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        string S;
        cin>>n>>S;
        
        int cnt = 0 ;
        for(int i=0;i<n-1;i++)
        {
            if(S[i]==S[i+1])
                cnt++;
        }
        
        cout<<(cnt/2)+(cnt%2)<<endl;
    }
    
    return 0;
}