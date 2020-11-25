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
        int op = 0 , A = 0 , B = 0 ;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='A')
                A++;
            else
            {
                if(A > 0 )
                {
                    A--;
                    op++;
                }
                else if(B > 0)
                {
                    B--;
                    op++;
                }
                else
                    B++;
            }
        }
        
        cout<<S.length() - 2*op <<endl;
    }
    
    return 0;
}
