#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int row , col ;
        cin>>row>>col ;
        int minimum = 200 , cnt_negetive = 0 , val;
        long long int sum = 0 ;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>val;
                if(val<0)
                    cnt_negetive++;
                minimum = min(minimum , abs(val));
                sum+=abs(val);
                    
            }
        }
        
        if(cnt_negetive%2)
            sum-=(2*minimum) ;
            
        cout<<sum<<endl;
    }
    
    return 0;
}

