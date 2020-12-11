#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , k;
        cin>>n>>k;
        vector<int>color(n);
        
        for(int i=0;i<n;i++)
            cin>>color[i] ;
        
        int min_op = INT_MAX ;
        for(int fixed_color = 1 ; fixed_color <= 100 ; fixed_color++)
        {
            int idx = 0 , day = 0;
            while(idx < n)
            {
                if(color[idx]!=fixed_color)
                {
                    day++;
                    idx+=k;
                }
                else
                    idx++;
            }
            min_op = min(min_op , day) ;
        }
        
        cout<<min_op<<endl;
    }
    
    return 0;
}