#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int a , b , c ;
        cin>>a>>b>>c;
        
        vector<int>A(a,0) , B(b,0) ;
        
        A[0] = 1 ;
        for(int i = 0 ; i < b - c + 1 ; i++)
            B[i] = 9 ;
            
        for(int i = 0 ; i < a ; i++)
            cout<<A[i];
        cout<<" ";
        for(int i = 0 ; i < b ; i++)
            cout<<B[i];
        cout<<endl;
    }
    return 0 ;
}