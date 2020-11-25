#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , c0 , c1 , h ;
        cin>>n>>c0>>c1>>h;
        string S;
        cin>>S;
        int cnt_zero = 0 , cnt_one = 0 ;
        
        for(int i=0;i<n;i++)
            S[i]=='0' ? cnt_zero++ : cnt_one++ ;
            
        long long int cost = 0 ;
        if(c0 > c1 + h)
            cost = cnt_one*c1 + cnt_zero*(c1 + h);
        else if(c1 > c0 + h)
            cost = cnt_zero*c0 + cnt_one*(c0 + h);
        else
            cost = cnt_one*c1 + cnt_zero*c0;
            
        cout<<cost<<endl;
    }
    
    return 0;
}