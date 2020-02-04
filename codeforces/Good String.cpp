#include<bits/stdc++.h>
using namespace std;

int main()
{
    int len;
    string S , T="";
    cin>>len;
    cin>>S;
    int i=0 ;
    while(i<len)
    {
        if(i==len-1)
            i++;
        else
        {
            if(S[i]!=S[i+1])
            {
                T+=S[i];
                T+=S[i+1];
                i+=2;
            }
            else
            {
                int j=i+1;
                while(j<len && S[i]==S[j])
                {
                    j++;
                }
                if(j<len && S[i]!=S[j])
                {
                    T+=S[i];
                    T+=S[j];
                }
                i=j+1;
            }
        }
    }
    cout<<S.length()-T.length()<<endl;
    cout<<T;
    return 0;
}