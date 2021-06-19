#include<bits/stdc++.h>
using namespace std ;

int  main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        bool flag = false ;
        
        int val; 
        for(int i = 0 ; i < n ; i++)
        {
            cin>>val;
            int x = sqrt(val) ;
            if(val != (x*x))
                flag = true ;
        }
        
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0 ;
}
