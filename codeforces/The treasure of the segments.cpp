#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<vector<int>>segment(n,vector<int>(2));
        vector<int>left(n);
        vector<int>right(n);
        
        for(int i=0;i<n;i++)
        {
            cin>>left[i]>>right[i];
            segment[i][0] = left[i] ;
            segment[i][1] = right[i] ;
        }
        
        sort(left.begin() , left.end());
        sort(right.begin() , right.end());
        
        int minimum_deletion = n - 1 ;
        for(int i = 0 ; i < n ; i++)
        {
            int cnt  = 0 ;
            int left_idx = lower_bound(right.begin() , right.end() , segment[i][0]) - right.begin() ;
            if(left_idx >= n)
                cnt+=n;
            else
            {
                if(right[left_idx] >= segment[i][0])
                    left_idx--;
                cnt+=(left_idx + 1);
            }
                
            int right_idx = upper_bound(left.begin() , left.end() , segment[i][1]) - left.begin() ;
            if(right_idx < n)
                cnt+=(n - right_idx);
              
            minimum_deletion = min(minimum_deletion , cnt);
        }
        
        cout<<minimum_deletion<<endl;
    }
    
    return 0;
}