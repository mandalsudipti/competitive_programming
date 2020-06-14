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
        int start = -1 , end = -1 ;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='1' && start==-1)
            {
                start=i;
                end=i;
            }
            else if(S[i]=='1' && start!=-1)
                end=i;
        }
        if(start==-1)
            cout<<n<<endl;
        else
            cout<<2*(end-start+1) + max(start,n-1-end)*2<<endl;
    }
    return 0;
}

