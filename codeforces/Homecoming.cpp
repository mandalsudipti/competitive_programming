#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b,p;
        cin>>a>>b>>p;
        string S;
        cin>>S;
        int  i=S.length()-1,j;
        while(i>0)
        {
            if(S[i-1]=='A')
            {
                if(a<=p)
                {
                    p-=a;
                    for(j=i-1;j>=0;j--)
                    {
                        if(S[j]!=S[i-1])
                            break;
                    }
                    i=j+1;
                }
                else
                    break;
                
            }
            else
            {
                if(b<=p)
                {
                   p-=b; 
                    for(j=i-1;j>=0;j--)
                    {
                        if(S[j]!=S[i-1])
                            break;
                    }
                    i=j+1;
                }
                else
                    break;
            }
            
        }
        cout<<max(1,i+1)<<endl;
    }
    return 0;
}