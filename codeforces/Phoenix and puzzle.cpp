#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int n ;
        cin>>n;
        
        bool flag = false ;
        
        if(n%4 == 0)
        {
            long long int tmp = n/4 ;
            long long int root = sqrt(tmp) ;
            if(tmp == root*root)
                flag = true ;
        }
        if(n%2 ==0)
        {
            long long int tmp = n/2 ;
            long long int root = sqrt(tmp);
            if(tmp == root*root)
                flag = true ;
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0 ;
}




