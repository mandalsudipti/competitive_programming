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
        string A , B ;
        cin>>A>>B;
        
        vector<bool>match(n,false);
        int cnt_A = 0 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            A[i] == '0' ? cnt_A-- : cnt_A++ ;
            
            if(cnt_A == 0)
                match[i] = true ;
        }
        
        int op = 0 ;
        bool possible = true ;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            if(!possible)
                break;
            if(op%2)
                A[i] == '0' ? A[i] = '1' : A[i] = '0' ;
                
            if(!match[i] && A[i] != B[i])
                possible = false ;
            else if(match[i] && A[i] != B[i])
                op++;
        }
        
        if(!possible)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    
    return 0 ;
}