#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        string S ;
        cin>>S ;
        int zero = 0 , one = 0 ;
        for(int i = 0 ; i <  n ; i++)
            S[i] == '0' ? zero++ : one++ ;
            
        if(S[0] == '0' || S[n-1] == '0' || zero%2 || one%2)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            string A , B ;
            for(int i = 0 ; i < n ; i++)
            {
                if(S[i] == '1')
                {
                    if(one)
                    {
                        A+='(';
                        B+='(';
                        one-=2;
                    }
                    else
                    {
                        A+=')';
                        B+=')';
                    }
                }
                else
                {
                    if(zero%2 == 0)
                    {
                        A+='(';
                        B+=')';
                        zero--;
                    }
                    else
                    {
                        A+=')';
                        B+='(';
                        zero--;
                    }
                }
            }
            cout<<"YES"<<endl;
            cout<<A<<endl;
            cout<<B<<endl;
        }
        
    }
    return 0 ;
}
