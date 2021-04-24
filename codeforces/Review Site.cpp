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
            
        int upvote = 0 , viewer ;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>viewer ;
            
            if(viewer == 1 || viewer == 3)
                upvote++ ;
        }
        cout<<upvote<<endl;
    }
    
    return 0 ;
}