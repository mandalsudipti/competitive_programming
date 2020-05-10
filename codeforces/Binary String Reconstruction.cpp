#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n0 , n1 , n2 ;
        cin>>n0>>n1>>n2;
        string S;
        for(int i=0;i<n0;i++)
            S+='0';
        if(n0!=0)
            S+='0';
            
        for(int i=0;i<n2;i++)
        {
            S+='1';
        }
        if(n2!=0)
            S+='1';
            
        if(n0!=0 && n2!=0)
            n1--;
        if(n0==0 && n2==0)
            S+='0';
        if(n2==0)
        {
            for(int i=1;i<=n1;i++)
            {
                if(i%2==1)
                    S+='1';
                else
                    S+='0';
            }
        }
        else
        {
            for(int i=1;i<=n1;i++)
            {
                if(i%2==1)
                    S+='0';
                else
                    S+='1';
            }
        }
        cout<<S<<endl;
    }
    return 0;
}
