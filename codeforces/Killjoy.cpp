#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , x ;
        cin>>n>>x;
        long long int upper_sum = 0 , lower_sum = 0 ,equal = 0 , val ;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            if(val>x)
                upper_sum+=(val-x);
            else if(val<x)
                lower_sum+=(x-val);
            else
                equal++;
        }
        
        if(upper_sum==lower_sum && upper_sum==0)
            cout<<"0"<<endl;
        else if( (upper_sum==lower_sum && upper_sum!=0) || equal>=1)
            cout<<"1"<<endl;
        else
            cout<<"2"<<endl;
    }
    
    return 0;
}
