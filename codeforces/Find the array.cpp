#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int s ;
        cin>>s;
        int cnt = 1 , cur = 1;
        s--;
        
        while(s > 0)
        {
            cnt++;
            if(s >= cur + 2)
            {
                s-=(cur+2);
                cur+=2;
            }
            else
                break;
        }
        
        cout<<cnt<<endl;
    }
    return 0 ;
}