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
        
        string enemy , gregor ;
        cin>>enemy>>gregor ;
        
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(gregor[i] == '0')
                continue ;
                
            if(enemy[i] == '0')
                cnt++ ;
            else 
            {
                if(i-1 >= 0 && enemy[i-1] == '1')
                {
                    cnt++ ;
                    enemy[i-1] = '*' ;
                }
                else if( i +1 < n && enemy[i+1] == '1')
                {
                    cnt++ ;
                    enemy[i+1] = '*' ;
                }
            }
        }
        
        cout<<cnt<<endl;
    }
    return 0 ;
}