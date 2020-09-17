#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , k ;
        cin>>n>>k;
        string S;
        cin>>S;
        bool possible = true;
        for(int i=0;i<k;i++)
        {
            if(!possible)
                break;
            bool one = false ;
            bool zero = false;
            
            for(int j=i;j<n;j+=k)
            {
                if(S[j]=='0')
                    zero = true;
                else if(S[j]=='1')
                    one = true;
            }
            
            if(zero && one)
            {
                possible = false;
                break;
            }
            for(int j=i;j<n;j+=k)
            {
                if(zero)
                    S[j]='0';
                else if(one)
                    S[j]='1';
            }
        }
        
        if(!possible)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int cnt_zero = 0 , cnt_one = 0 ;
        for(int i=0;i<k;i++)
        {
            if(S[i]=='0')
                cnt_zero++;
            else if(S[i]=='1')
                cnt_one++;
        }
        
        if((k- cnt_one - cnt_zero)< abs(cnt_zero- cnt_one))
            possible = false;
        if(!possible)
        {
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;
    }
    
    return 0;
}