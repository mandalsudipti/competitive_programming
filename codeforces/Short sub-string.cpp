#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string S;
        cin>>S;
        string ans;
        for(int i=0;i<S.length();i++)
        {
            if(i%2==0)
                ans+=S[i];
        }
        ans+=S[S.length()-1];
        cout<<ans<<endl;
    }
    return 0;
}