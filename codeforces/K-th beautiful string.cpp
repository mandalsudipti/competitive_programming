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
        string S(n,'a');
        for(int i=n-2;i>=0;i--)
        {
            if(k<=n-1-i)
            {
                S[i]='b';
                S[n-k]='b';
                break;
            }
            k-=(n-1-i);
        }
        cout<<S<<endl;
    }
    return 0;
}
