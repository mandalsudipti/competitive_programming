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
        
        int min_remove = INT_MAX ;
        
        for(int i = 0 ; i < 26 ; i++)
        {
            char cur = 'a' + i ;
            int left = 0 , right = S.length() - 1 , count = 0 ;
            bool possible = true ;
            
            while(right >= left)
            {
                if(S[left] == S[right])
                {
                    left++ ;
                    right-- ;
                }
                else
                {
                    count++ ;
                    if(S[left] == cur)
                        left++ ;
                    else if(S[right] == cur)
                        right--;
                    else
                    {
                        possible = false ;
                        break ;
                    }    
                }
            }
            
            if(possible)
                min_remove = min(min_remove , count) ;
        }
        
        if(min_remove == INT_MAX)
            cout<<"-1"<<endl;
        else
            cout<<min_remove<<endl;
    }
    
    return 0 ;
}