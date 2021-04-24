#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , val;
        cin>>n ;
        
        int num1 = -1, freq1 = 0, num2 = -1 , freq2 = 0 , pos1 , pos2;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>val;
            if(val == num1 || num1 == -1)
            {
                num1 = val ;
                freq1++;
                pos1 = i+1 ;
            }
            else
            {
                num2 = val ;
                freq2++;
                pos2 = i+1 ;
            }
        }
        
        if(freq1 == 1)
            cout<<pos1<<endl;
        else
            cout<<pos2<<endl;
        
    }
    
    return 0;
}
