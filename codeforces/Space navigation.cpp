#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int x , y ;
        cin>>x>>y;
        int U = 0 , D = 0 , L = 0 , R = 0 ;
        string S ;
        cin>>S ;
        
        for(int i = 0 ; i < S.length() ; i++)
        {
            if(S[i] == 'U')
                U++;
            else if(S[i] == 'D')
                D++;
            else
                S[i] == 'L' ? L++ : R++ ;
        }
        
        int pos_x = R - L , pos_y = U - D ;
        
        bool possible = true ;
        if(pos_x > x && (pos_x - x) > R)
            possible = false ;
        if(pos_x < x && (x - pos_x) > L)
            possible = false;
        if(pos_y > y && (pos_y - y) > U)
            possible = false;
        if(pos_y < y && (y - pos_y) > D)
            possible = false;
            
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}