#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , val ;
        cin>>n ;
        bool possible = true ;
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>val;
            if(val < 0)
                possible = false ;
        }
        
        if(!possible)
            cout<<"NO\n" ;
        else
        {
            cout<<"YES\n" ;
            cout<<"101\n";
            for(int i = 0 ; i <= 100 ; i++)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0 ;
}
