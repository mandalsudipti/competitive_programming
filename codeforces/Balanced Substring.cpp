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
        
        map<int,int>diff ;
        int a = 0 , b = 0 ;
        bool found = false ;
        for(int i = 0 ; i < n ; i++)
        {
            S[i] == 'a' ? a++ : b++ ;
            
            if(a == b)
            {
                found = true ;
                cout<<"1 "<<(i+1)<<endl;
                break ;
            }
            else if(diff.find(a - b) != diff.end())
            {
                found = true ;
                cout<<diff[a - b] + 2 <<" "<<(i+1)<<endl;
                break ;
            }
            else
                diff[a-b] = i ;
        }
        
        if(!found)
            cout<<"-1 "<<"-1"<<endl ;
    }
    
    return 0 ;
}