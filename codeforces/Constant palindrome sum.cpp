#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n+1];
        for(int i=1;i<=n;i++)
            cin>>arr[i];
            
        vector<int>line_start(2*k+2,0);
        vector<int>line_end(2*k+2,0);
        vector<int>pair_sum(2*k+1,0);
        for(int i=1;i<=n/2;i++)
        {
            line_start[min(arr[i],arr[n-i+1])+1]++;
            line_end[max(arr[i],arr[n-i+1])+k+1]++;
            pair_sum[arr[i]+arr[n-i+1]]++;
        }
        
        vector<int>line_at(2*k+1,0);
        for(int i=1;i<=2*k;i++)
        {
            line_at[i]=line_at[i-1]+line_start[i]-line_end[i];
        }
        
        int minimum_change = n;
        for(int i=1;i<=2*k;i++)
        {
            int change_one = line_at[i] - pair_sum[i] ;
            int change_two = (n/2) - change_one - pair_sum[i] ;
            minimum_change = min(minimum_change , (change_one+change_two*2));
        }
        
        cout<<minimum_change<<endl;
    }
    return 0;
}

