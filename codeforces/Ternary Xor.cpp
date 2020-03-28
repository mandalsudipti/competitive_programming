#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int len;
        cin>>len;
        string S;
        cin>>S;
        string T="",L="";
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='2')
            {
                T+='1';
                L+='1';
            }
            else if(S[i]=='0')
            {
                T+='0';
                L+='0';
            }
            else if(S[i]=='1')
            {
                T+='1';
                L+='0';
                break;
            }
        }
        int diff=S.length()-T.length();
        for(int i=0;i<diff;i++)
            T+='0';
        for(int i=L.length();i<S.length();i++)
            L+=S[i];
       
        cout<<T<<endl;
        cout<<L<<endl;
    }
    return 0;
}