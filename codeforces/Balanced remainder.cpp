#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , val;
        cin>>n;
        vector<int>rem(3,0);
        
        for(int i = 0 ; i < n ;i++)
        {
            cin>>val;
            val = val % 3 ;
            rem[val]++;
        }
        int avg = n/3 , count_move = 0;
        for(int i = 0 ; i < 3 ; i++)
        {
            if(rem[i] <= avg)
                continue;
            int idx = i , t = 2;
            while(t--)
            {
                idx = (i + t + 1)%3 ;
                
                if(rem[idx] < avg && rem[i] > avg)
                {
                    int add = min(avg - rem[idx] , rem[i] - avg);
                    count_move+=((t+1) * add);
                    rem[i]-=add;
                    rem[idx]+=add;
                }
            }
        }
        
        cout<<count_move<<endl;
    }
    
    return 0;
}
