#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , m , val ;
        cin>>n>>m;
        vector<int>rem(m,0);
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>val;
            rem[val%m]++;
        }
        
        int count = 0 ;
        for(int i = 0 ; i < m ; i++)
        {
            if(i == 0 && rem[i] > 0)
            {
                count++;
                continue;
            }
            int other = m - i ;
            
            if(other == i && rem[i] > 0)
                count++;
            else if(rem[i] > 0)
            {
                if(rem[other] == 0) 
                    count+=rem[i];
                else
                    count+=max(1,abs(rem[i] - rem[other]));
                    
                rem[i] = rem[other] = 0 ;
            }
        }
        cout<<count<<endl;
    }
    
    return 0;
}

